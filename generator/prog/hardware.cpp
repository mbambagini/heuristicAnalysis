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


/*!
 * Let users add as many processors as they want.
 * First of all, users insert the available processor types and then,
 * the deployed cores are specified
 */
int add_processors(Hardware& hw, int nOfResources);


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

	if (add_processors(hw, nOfRes)<1)
		fatal_error("data not valid");

	//output - serialization
	fstream output(FLAGS_binaryFile.c_str(), ios::out |ios::trunc|ios::binary);
	if (!hw.SerializeToOstream(&output))
		fatal_error("failed to serialize");

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}



int add_processors(Hardware& hw, int nOfResources)
{
	cout<<"ADD PROCESSOR TYPES"<<endl;

	int id = 0;
	do {
		ProcessorType *type = hw.add_types();
		type->set_id(id++);

		double val;
		cout<<"Add p_active : ";
		cin>>val;
		type->set_pactive(val);

		cout<<"Add p_idle : ";
		cin>>val;
		type->set_pidle(val);

		cout<<"Add p_sleep : ";
		cin>>val;
		type->set_psleep(val);

		cout<<"Add p_switching : ";
		cin>>val;
		type->set_pswitching(val);

		cout<<"Add BET : ";
		cin>>val;
		type->set_bet(val);

		cout<<"Add instruction/second for each resource"<<endl;
		for (int i=0; i<nOfResources; i++) {
			cout<<"Resource "<<i<<": ";
			cin>>val;
			type->add_speed(val);
		}

		char c;
		cout<<"Add a new processor type (Y/n)? ";
		cin>>c;
		if (c=='N' || c=='n')
			break;
	} while(true);

	cout<<"ADD PROCESSORS"<<endl;
	do {
		int i;
		cout<<"Insert processor type : ";
		cin>>i;
		if (i>=id)
			continue;
		hw.add_processors(i);

		char c;
		cout<<"Add a new processor (Y/n)? ";
		cin>>c;
		if (c=='N' || c=='n')
			break;
	} while (true);

	return 1;
}



void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

