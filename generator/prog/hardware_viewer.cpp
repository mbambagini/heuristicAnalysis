/*! \file hardware_viewer.cpp
 *  \brief print the core information on the standard output
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include <limits>

#include <stdio.h>
#include <stdlib.h>

#include <problem.pb.h>

#include <gflags/gflags.h>


using namespace std;


using namespace Problem;


DEFINE_string(srcFile, "", "Binary input file");


void fatal_error (string msg);


int main (int argc, char* argv[])
{
	//check parameters
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	google::ParseCommandLineFlags(&argc, &argv, false);

	if (FLAGS_srcFile.compare("")==0)
		fatal_error("the input file is mandatory");

	//architecture definition 
	Hardware hw;
	fstream input(FLAGS_srcFile.c_str(), ios::in | ios::binary);
	if (!hw.ParseFromIstream(&input))
		fatal_error("failed to parse the input file");
	input.close();

	//printing
	cout<<setw(20)<<"#resources:"<<setw(10)<<hw.nofresources();
	cout<<" ("<<hw.resources(0);
	for (int i=1; i<hw.nofresources(); i++) 
		cout<<", "<<hw.resources(i);
	cout<<")"<<endl;
	cout<<setw(20)<<"#clusters:"<<setw(10)<<hw.nofclusters()<<endl;
	cout<<setw(20)<<"CPU per Cluster:"<<setw(10)<<hw.cpc()<<endl<<endl;
	cout<<setw(10)<<"Speed"<<setw(10)<<"K0"<<setw(10)<<"K1*c";
	cout<<setw(10)<<"K2*c^2"<<setw(10)<<"K3*c^3"<<endl;
	for (int i=0; i<hw.cons_size(); i++) {
		ConsAtSpeed cons = hw.cons(i);
		cout.setf(ios::fixed);
		cout<<setw(10)<<setprecision(3)<<cons.speed();
		cout<<setw(10)<<cons.coeffs().k0()<<setw(10)<<cons.coeffs().k1();
		cout<<setw(10)<<cons.coeffs().k2()<<setw(10)<<cons.coeffs().k3()<<endl;
	}

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}


void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

