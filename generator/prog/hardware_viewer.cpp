/*! \file hardware_viewer.cpp
 *  \brief print the core information on the standard output
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

#include <hardware_printer.hpp>



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

	HardwarePrinter ser;
	ser.serialize(cout, hw);

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}


void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

