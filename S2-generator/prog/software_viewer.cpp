/*! \file software_viewer.cpp
 *  \brief print the task information on the standard output
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

#include <randomizer.hpp>

#include <problem.pb.h>

#include <gflags/gflags.h>


using namespace std;


DEFINE_string(srcFile, "", "Input file");


void fatal_error (string msg);


int main (int argc, char* argv[])
{
	//check parameters
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	google::ParseCommandLineFlags(&argc, &argv, false);

	if (FLAGS_srcFile.compare("")==0)
		fatal_error("the input file is mandatory");

	Problem::Software sw;
	fstream input(FLAGS_srcFile.c_str(), ios::in | ios::binary);
	if (!sw.ParseFromIstream(&input))
		fatal_error("failed to parse the input file");

	cout<<setw(20)<<"#Resources:"<<setw(15)<<sw.nofresources()<<endl;
	cout<<setw(20)<<"Utilization:"<<setw(15)<<sw.u()<<endl;
	cout<<setw(20)<<"Real utilization:"<<setw(15)<<sw.real_u()<<endl<<endl;

	cout<<"Tasks:"<<endl;
	cout<<setw(5)<<"ID"<<setw(10)<<"T"<<setw(10)<<"D"<<setw(12)<<"U";
	cout<<setw(10)<<"C";
	for (int j=0; j<sw.nofresources(); j++) {
		stringstream ss;
		ss<<"C("<<j<<")";
		cout<<setw(10)<<ss.str();
	}
	cout<<endl;
	for (int j=0; j<sw.tasks_size(); j++) {
		const Problem::Task t = sw.tasks(j);
		cout<<setw(5)<<t.id()<<setw(10)<<t.period()<<setw(10)<<t.deadline();
		cout.setf(ios::fixed);
		cout<<setw(12)<<setprecision(4)<<(double)t.wcet()/t.period();
		cout<<setw(10)<<t.wcet();
		for (int k=0; k<sw.nofresources(); k++)
			cout<<setw(10)<<t.wcets(k);
		cout<<endl;
	}
	cout<<endl;

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}

void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

