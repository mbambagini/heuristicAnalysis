#include <iostream>
#include <iomanip>
#include <fstream>

#include <list>

#include <gflags/gflags.h>

#include <simulations.pb.h>


DEFINE_string(binaryFile, "","");


using namespace std;


int main (int argc, char* argv[])
{

	GOOGLE_PROTOBUF_VERIFY_VERSION;
	google::ParseCommandLineFlags(&argc, &argv, false);

	if (FLAGS_binaryFile=="") {
		cerr<<"Error: specify a valid input file"<<endl;
		exit(0);
	}

	Simulations::Simulation sim;

	sim.set_feasible(true);
	sim.set_csa(0);
	sim.set_tsa(0);

	cout<<"Insert tasks"<<endl;
	int i = 0;
	char comm;
	do {
		int p, c, core, num;
		cout<<"Type period, wcet, core, num: ";
		cin>>p;
		cin>>c;
		cin>>core;
		cin>>num;
		for (int j=0; j<num; j++) {
			Simulations::Task *task = sim.add_tasks();
			task->set_id(i++);
			task->set_period(p);
			task->set_deadline(p);
			task->set_wcet(c);
			task->set_core(core++);
		}
		cout<<"Another task? ";
		cin>>comm;
	} while(comm=='y'||comm=='Y');

	int n_cores;
	cout<<"N of cores: ";
	cin>>n_cores;
	std::vector<bool> core_array(n_cores);
	for (int j=0; j<n_cores; j++)
		core_array[j] = true;

	cout<<"Insert cores"<<endl;
	std::list<int> core_list;
	do {
		int id, num;
		double u;
		cout<<"Type id, utilization and num: ";
		cin>>id;
		cin>>u;
		cin>>num;
		for (int j=0; j<num; j++) {
			Simulations::Core *core = sim.add_cores();
			core->set_id(id++);
			core->set_u(u);
			core_array[id] = false;
		}
		cout<<"Another core? ";
		cin>>comm;
	} while(comm=='y'||comm=='Y');
	core_list.sort();

	for (int j=0; j<n_cores; j++) {
		if (core_array[j]) {
			Simulations::Core *core = sim.add_cores();
			core->set_id(j);
			core->set_u(0.0);
		}
	}

	//output - serialization
	fstream output(FLAGS_binaryFile.c_str(), ios::out|ios::trunc|ios::binary);
	if (!sim.SerializeToOstream(&output))
		return false;
	output.close();

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}

