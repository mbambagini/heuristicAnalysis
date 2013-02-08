/*! \file viewer.cpp
 *
 * print the simulation input and output on the standard output
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

#include <gflags/gflags.h>

#include <simulations.pb.h>


DEFINE_string(simFile, "","File with configuration and result of a simulation");


using namespace std;


int main (int argc, char* argv[])
{

	GOOGLE_PROTOBUF_VERIFY_VERSION;
	google::ParseCommandLineFlags(&argc, &argv, false);

	if (FLAGS_simFile=="") {
		cerr<<"Error: specify a valid simulation file"<<endl;
		exit(0);
	}

	Simulations::Simulation sim;

	fstream input(FLAGS_simFile.c_str(), ios::in | ios::binary);
	if (!sim.ParseFromIstream(&input)) {
		cerr<<"Error: Failed to parse "<<FLAGS_simFile<<"."<<endl;
		exit(0);
	}
	input.close();

	cout<<"SIMULATION ("<<(!sim.feasible()?"NOT ":"")<<"feasible)"<<endl;
	cout<<"Core ("<<sim.core()<<"), bet ("<<sim.bet()<<")"<<endl;
	cout<<"#Tasks ("<<sim.tasks_size()<<"), utilization ("<<sim.utilization()
																	<<")"<<endl;
	cout<<setw(10)<<"ID";
	cout<<setw(15)<<"WCET";
	cout<<setw(15)<<"PERIOD";
	cout<<setw(15)<<"DEADLINE"<<endl;
	for (int i=0; i<sim.tasks_size(); i++) {
		const Simulations::Task& t = sim.tasks(i);
		cout<<setw(10)<<t.id();
		cout<<setw(15)<<t.wcet();
		cout<<setw(15)<<t.period();
		cout<<setw(15)<<t.deadline()<<endl;
	}

	cout<<endl<<"RESULTS"<<endl;
	cout<<setw(12)<<"ACTIVE";
	cout<<setw(12)<<"IDLE";
	cout<<setw(12)<<"SLEEP";
	cout<<setw(12)<<"SWITCHING";
	cout<<setw(8)<<"OFF?"<<endl;
	cout<<setw(12)<<sim.res().activetime();
	cout<<setw(12)<<sim.res().idletime();
	cout<<setw(12)<<sim.res().sleeptime();
	cout<<setw(12)<<sim.res().switchingtime();
	cout<<setw(8)<<sim.res().off()<<endl;

	cout<<"#preemptions: "<<sim.res().nofpreemptions()<<endl;
	cout<<"#invocations: "<<sim.res().nofinvocations()<<endl;
	cout<<"#sleeps: "<<sim.res().nofsleeps()<<endl;

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}

