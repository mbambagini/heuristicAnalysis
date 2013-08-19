/*! \file hardware.cpp
 *  \brief let user define the available hardware
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <stdio.h>
#include <stdlib.h>

#include <problem.pb.h>

#include <gflags/gflags.h>


using namespace std;
using namespace Problem;


DEFINE_string(binaryFile, "", "Binary output file");


int add_speed (Hardware& hw);

void fatal_error (string msg);



int main (int argc, char* argv[])
{
	//check parameters
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	google::ParseCommandLineFlags(&argc, &argv, false);

	if (FLAGS_binaryFile.compare("")==0)
		fatal_error("the output file is mandatory");

	//architecture definition 
	Hardware hw;

	int nOfRes;
	cout<<"Add number of resources: ";
	cin>>nOfRes;
	hw.set_nofresources(nOfRes);

	for(int i=0; i<nOfRes; i++) {
		int tmp;
		cout<<"Number of commited resources of type "<<i<<" per second: ";
		cin>>tmp;
		hw.add_resources(tmp);
	}

	int nOfClusters;
	cout<<"Add number of clusters: ";
	cin>>nOfClusters;
	hw.set_nofclusters(nOfClusters);

	int CPUperCluster;
	cout<<"Add number of CPU per cluster: ";
	cin>>CPUperCluster;
	hw.set_cpc(CPUperCluster);

	double idle;
	cout<<"Add power consumption in idle: ";
	cin>>idle;
	hw.set_idle(idle);

	add_speed(hw);

	//output - serialization
	fstream output(FLAGS_binaryFile.c_str(), ios::out |ios::trunc|ios::binary);
	if (!hw.SerializeToOstream(&output))
		fatal_error("failed to serialize");

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}


int add_speed (Hardware& hw)
{
	do {
		ConsAtSpeed *cons = hw.add_cons();
		Coefficients *coeffs = cons->mutable_coeffs();

		double speed;
		cout<<"Add speed (GHz): ";
		cin>>speed;
		cons->set_speed(speed);

		double coeff;
		cout<<"Add k0: ";
		cin>>coeff;
		coeffs->set_k0(coeff);

		cout<<"Add k1: ";
		cin>>coeff;
		coeffs->set_k1(coeff);

		cout<<"Add k2: ";
		cin>>coeff;
		coeffs->set_k2(coeff);

		cout<<"Add k3: ";
		cin>>coeff;
		coeffs->set_k3(coeff);

		char c;
		cout<<"Add a new speed (Y/n)? ";
		cin>>c;
		if (c=='N' || c=='n')
			break;
	} while(true);

	return 1;
}


void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

