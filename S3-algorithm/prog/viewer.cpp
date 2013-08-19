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


DEFINE_string(srcFile, "","Input file with the partitioning");


using namespace std;


int main (int argc, char* argv[])
{

	GOOGLE_PROTOBUF_VERIFY_VERSION;
	google::ParseCommandLineFlags(&argc, &argv, false);

	if (FLAGS_srcFile=="") {
		cerr<<"Error: specify a valid input file"<<endl;
		exit(0);
	}

	Simulations::Simulation sim;

	fstream input(FLAGS_srcFile.c_str(), ios::in | ios::binary);
	if (!sim.ParseFromIstream(&input)) {
		cerr<<"Error: Failed to parse "<<FLAGS_srcFile<<"."<<endl;
		exit(0);
	}
	input.close();

	cout<<"SIMULATION ("<<(!sim.feasible()?"NOT ":"")<<"feasible)"<<endl;
	cout<<"#Core ("<<sim.cores_size()<<")"<<endl;
	cout<<"#Tasks ("<<sim.tasks_size()<<")"<<endl;
	cout<<"CSA ("<<sim.csa()<<"), TSA ("<<sim.tsa()<<")"<<endl<<endl;

	cout<<"TASKS"<<endl;
	cout<<setw(10)<<"ID"<<setw(15)<<"WCET"<<setw(15)<<"PERIOD";
	cout<<setw(15)<<"DEADLINE"<<setw(15)<<"U"<<setw(10)<<"CORE"<<endl;
	for (int i=0; i<sim.tasks_size(); i++) {
		const Simulations::Task& t = sim.tasks(i);
		cout<<setw(10)<<t.id()<<setw(15)<<t.wcet()<<setw(15)<<t.period();
		cout<<setw(15)<<t.deadline()<<setw(15)<<(double)t.wcet()/t.period();
		cout<<setw(10)<<t.core()<<endl;
	}

	cout<<endl<<setw(10)<<"CORE"<<setw(20)<<"Utilization"<<endl;
	for (int i=0; i<sim.cores_size(); i++)
		cout<<setw(10)<<i<<setw(20)<<sim.cores(i).u()<<endl;

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}

