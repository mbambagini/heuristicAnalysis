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


DEFINE_string(resultsFile, "", "File containing all the results");

DEFINE_string(simCore1, "", "File to evaluate");
DEFINE_string(simCore2, "", "File to evaluate");
DEFINE_string(simCore3, "", "File to evaluate");
DEFINE_string(simCore4, "", "File to evaluate");
DEFINE_string(simCore5, "", "File to evaluate");
DEFINE_string(simCore6, "", "File to evaluate");
DEFINE_string(platformFile, "", "Platform model");

DEFINE_int32(TSA, 0, "");
DEFINE_int32(CSA, 0, "");

DEFINE_double(U, 0.0, "nominal utilization");


using namespace std;


/*!
 * parse a single simulation (featuring the assignment of a core)
 */
void parseSimulation (string filename, list<Simulations::Simulation>& l);

/*!
 * critical error, the execution is aborted
 */
void fatal_error (string msg);


int main (int argc, char* argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, false);

	//load all the simulation (one for each core). The core files not passed as
	//argument are ignored
	list<Simulations::Simulation> sims;
	parseSimulation(FLAGS_simCore1, sims);
	parseSimulation(FLAGS_simCore2, sims);
	parseSimulation(FLAGS_simCore3, sims);
	parseSimulation(FLAGS_simCore4, sims);
	parseSimulation(FLAGS_simCore5, sims);
	parseSimulation(FLAGS_simCore6, sims);
	if (sims.size()==0)
		return 1;

	Problem::Hardware platform;
	ifstream input(FLAGS_platformFile.c_str(), ios::in | ios::binary);
	if (!platform.ParseFromIstream(&input))
		fatal_error ("Failed to parse "+FLAGS_platformFile);
	input.close();
	GlobalResults::GlobalResult res;
	ifstream input1(FLAGS_resultsFile.c_str(), ios::in | ios::binary);
	if ((bool)input1) {
		if (!res.ParseFromIstream(&input1))
			fatal_error ("Failed to parse "+FLAGS_resultsFile);
	}
	input1.close();
	GlobalResults::AlgorithmInvocation* inv = res.add_results();
	inv->set_tsa(FLAGS_TSA);
	inv->set_csa(FLAGS_CSA);
	inv->set_u(FLAGS_U);
	inv->set_nofcores(platform.processors_size());
	if (sims.size()>0)
		inv->set_feasible(true);
	else
		inv->set_feasible(false);
	for (list<Simulations::Simulation>::iterator it = sims.begin();
														 it!=sims.end(); it++) {
		GlobalResults::Consumption* c = inv->add_cons();
		inv->set_feasible(it->feasible());
		c->set_core(it->core());
		c->set_u(it->utilization());
		c->set_noftasks(it->tasks_size());
		double power = 0.0;
		const Simulations::Result& r = it->res();
		const Problem::ProcessorType& p = platform.types(platform.processors(
																   it->core()));
		if (!(r.off())) {
			power = p.pactive()*r.activetime();
			power += p.pidle()*r.idletime();
			power += p.psleep()*r.sleeptime();
			power += p.pswitching()*r.switchingtime();
		}
		c->set_meanp(power);
	}
	fstream output(FLAGS_resultsFile.c_str(), ios::out|ios::trunc|ios::binary);
	if (!res.SerializeToOstream(&output))
		return false;
	output.close();
	return 0;
}


void parseSimulation (string filename, list<Simulations::Simulation>& l)
{
	Simulations::Simulation sim;
	if (filename.compare("")==0)
		return;
	fstream input(filename.c_str(), ios::in | ios::binary);
	if (!sim.ParseFromIstream(&input))
		fatal_error ("Failed to parse "+filename);
	input.close();
	if (sim.feasible())
		l.push_back(sim);
}


void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

