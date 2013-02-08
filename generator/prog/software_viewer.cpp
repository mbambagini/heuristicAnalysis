/*! \file software_viewer.cpp
 *  \brief print the task information on the standard output
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <randomizer.hpp>

#include <software_printer.hpp>

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

	Problem::Software set;
	fstream input(FLAGS_srcFile.c_str(), ios::in | ios::binary);
	if (!set.ParseFromIstream(&input))
		fatal_error("failed to parse the input file");

	SoftwarePrinter sw;
	sw.serialize(cout, set);

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}

void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

