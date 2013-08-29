/*! \file collector.cpp
 *
 * collect and compact all the simulations of a problem instance (one for each
 * core) and append them to a single data structure.
 * The information is appended if and only if the partitioning is feasible
 */

#include <stdlib.h>
#include <time.h>
#include <list>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

#include <simulations.pb.h>
#include <results.pb.h>
#include <problem.pb.h>

#include <gflags/gflags.h>


DEFINE_string(binaryFile, "", "File containing all the results");

DEFINE_string(hwFile, "", "");
DEFINE_string(partitionFile, "", "");


using namespace std;



double get_power (std::vector<int> & nActiveCores, const Problem::Hardware& hw);

void compute_mean_power (Results::Consumption* cons,
						 const Problem::Hardware& hw,
						 const Simulations::Simulation sim, bool sfa,
						 double alpha);



/*!
 * critical error, the execution is aborted
 */
void fatal_error (string msg);



struct t_speed_rec {
	int id;
	double freq;
	double speed;
};
std::list<t_speed_rec> speeds_rec;
t_speed_rec highest_speed;

struct t_core_load {
	int id;
	double load;
	double speed;
	int speed_id;
	bool operator< (t_core_load b) {
		return load<b.load;
	}
};

int main (int argc, char* argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, false);

	if (FLAGS_hwFile.compare("")==0 || FLAGS_partitionFile.compare("")==0
					|| FLAGS_binaryFile.compare("")==0)
		fatal_error("The files are mandatory");

	Results::Result result;
	ifstream input(FLAGS_binaryFile.c_str(), ios::in | ios::binary);
	if (input) {
		if (!result.ParseFromIstream(&input))
			fatal_error ("Failed to parse "+FLAGS_binaryFile);
	} else
			result.set_hwfile(FLAGS_hwFile);
	input.close();

	Problem::Hardware hw;
	input.open(FLAGS_hwFile.c_str(), ios::in | ios::binary);
	if (!hw.ParseFromIstream(&input))
		fatal_error ("Failed to parse "+FLAGS_hwFile);
	input.close();

	Simulations::Simulation sim;
	input.open(FLAGS_partitionFile.c_str(), ios::in | ios::binary);
	if (!sim.ParseFromIstream(&input))
		fatal_error ("Failed to parse "+FLAGS_partitionFile);
	input.close();

////////////////////////////////////////////////////////////////////////////////

	int tmp = 0;
	for (int i=1; i<hw.cons_size(); i++)
		if (hw.cons(i).speed( ) > hw.cons(tmp).speed())
			tmp = i;
	highest_speed.id = tmp;
	highest_speed.freq = hw.cons(tmp).speed();
	highest_speed.speed = 1.0;

	for (int i=0; i<hw.cons_size(); i++) {
		t_speed_rec tmp;
		tmp.id = i;
		tmp.freq = hw.cons(i).speed();
		tmp.speed = tmp.freq / highest_speed.freq;
		speeds_rec.push_back(tmp);
	}


////////////////////////////////////////////////////////////////////////////////

	Results::Execution *iter = result.add_iterations();

	iter->set_tsa (sim.tsa());
	iter->set_csa (sim.csa());
	iter->set_feasible(sim.feasible());
	iter->set_partitioningfile(FLAGS_partitionFile);
	iter->set_n(sim.tasks_size());
	double uu = 0.0;
	for (int i=0; i<sim.cores_size(); i++)
		uu += sim.cores(i).u();
	iter->set_u(uu);

	//no sfa
	Results::Consumption* no_sfa = iter->mutable_no_sfa();
	compute_mean_power(no_sfa, hw, sim, false, 0.0);
	//sfa
	for (double a = 0.0; a<=1.0; a+=0.1) {
		Results::Consumption* sfa = iter->add_sfa();
		compute_mean_power(sfa, hw, sim, true, a);
	}

	//output - serialization
	fstream output(FLAGS_binaryFile.c_str(), ios::out|ios::trunc|ios::binary);
	if (!result.SerializeToOstream(&output))
		return false;
	output.close();

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}

void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}



void compute_mean_power (Results::Consumption* cons,
						 const Problem::Hardware& hw,
						 const Simulations::Simulation sim,
						 bool sfa,
						 double alpha)
{

	std::list<t_core_load> u;
	for (int i=0; i<sim.cores_size(); i++)
		if (sim.cores(i).u()>0.0) {
#ifdef DEBUG
			cout<<"Core "<<i<<": initial U: "<<sim.cores(i).u();
#endif
			t_core_load tmp;
			tmp.id = i;
			if (sfa) {
				double load = sim.cores(i).u();
				tmp.load = load;
				tmp.speed_id = highest_speed.id;
				tmp.speed = highest_speed.speed;

				for (std::list<t_speed_rec>::iterator iter = speeds_rec.begin();
												iter!=speeds_rec.end(); iter++){
					t_speed_rec local = *iter;
					double new_u = alpha*load+(1-alpha)*load/local.speed;
					if (tmp.speed>local.speed && new_u<=1.0) {
						tmp.load = new_u;
						tmp.speed_id = local.id;
						tmp.speed = local.speed;
					}
				}
			} else {
				tmp.load = sim.cores(i).u();
				tmp.speed = 1.0;
				tmp.speed_id = highest_speed.id;
			}
#ifdef DEBUG
			cout<<", new U: "<<tmp.load<<endl;
#endif
			u.push_back(tmp);
		}
//	unsigned int nOfActiveCores = u.size();
	//activeCores[id] --> speed_id==id
	std::vector<int> activeCores(speeds_rec.size());
	for (std::list<t_core_load>::iterator it=u.begin(); it!=u.end(); it++)
		activeCores[it->speed_id]++;
	u.sort();

	cons->set_nactivecores(speeds_rec.size());
	cons->set_alpha(alpha);

	double t = 0.0;
	double global_p = 0.0;
	for (std::list<t_core_load>::iterator it = u.begin(); it!=u.end(); it++) {
		double act_u = it->load;
		double p = get_power(activeCores, hw);
		global_p += (act_u-t)*p;

#ifdef DEBUG
		cout<<"Step at u="<<act_u<<" previous at "<<t<<endl;
		cout<<"Consumption: "<<p<<", norm: "<<(act_u-t)*p<<", long: "<<(act_u-t)<<endl;
		cout<<"Cores: ";
		for (unsigned int j=0; j<activeCores.size(); j++)
			cout<<activeCores[j]<<" ";
		cout<<endl;
#endif

		t = act_u;
		activeCores[it->speed_id]--;

		if (activeCores[it->speed_id]<0 || t>1.0)
			fatal_error("wtf?");
	}
	global_p += (1.0-t)*hw.idle();
	cons->set_meanpower(global_p);

#ifdef DEBUG
	cout<<"GLOBAL: "<<global_p<<endl;
	cout<<"IDLE: "<<hw.idle()<<endl;
	cout<<"---------------------------------------------------"<<endl;
#endif
}



double get_power (std::vector<int>& nActiveCores, const Problem::Hardware& hw)
{
	int num = 0;
	for (unsigned int i=0; i<nActiveCores.size(); i++)
		num += nActiveCores[i];
	double x = (double)num/hw.cpc();

	double average_power = 0.0;
	for (unsigned int i=0; i<nActiveCores.size(); i++) {
		if (nActiveCores[i]==0)
			continue;
		double k0 = hw.cons(i).coeffs().k0();
		double k1 = hw.cons(i).coeffs().k1();
		double k2 = hw.cons(i).coeffs().k2();
		double k3 = hw.cons(i).coeffs().k3();
		double p = k3*x*x*x+k2*x*x+k1*x+k0;
#ifdef DEBUG
		cout<<p<<endl;
#endif
		average_power += p * ((double)nActiveCores[i]/num);
	}
	return average_power;
}

