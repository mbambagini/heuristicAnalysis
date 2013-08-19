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


DEFINE_string(binaryFile, "", "File containing all the results");

DEFINE_string(hwFile, "", "");
DEFINE_string(partitionFile, "", "");


using namespace std;


/*!
 * critical error, the execution is aborted
 */
void fatal_error (string msg);


int main (int argc, char* argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, false);

	if (FLAGS_hwFile.compare("")==0 || FLAGS_swFile.compare("")==0
					|| FLAGS_partitionFile.compare("")==0
					|| FLAGS_binaryFile.compare("")==0)
		fatal_error("The files are mandatory");

	Results::Result result;
	ifstream input(FLAGS_binaryFile.c_str(), ios::in | ios::binary);
	if (input) {
		if (!result.ParseFromIstream(&input))
			fatal_error ("Failed to parse "+FLAGS_binaryFile);
		else
			result.set_hwfile(FLAGS_hwFile);
	}
	input.close();

	Problem::Hardware hw;
	input.open(FLAGS_hwFile.c_str(), ios::in | ios::binary);
	if (!hw.ParseFromIstream(&input))
		fatal_error ("Failed to parse "+FLAGS_hwFile);
	input.close();

	Simulations::Simulation sim;
	input.open(FLAGS_partitionFile.c_str(), ios::in | ios::binary);
	if (!sim.ParseFromIstream(&input))
		fatal_error ("Failed to parse "+FLAGS_partitionFile);
	input.close();

	Results::Execution *iter = result.add_iterations();

	iter->set_tsa (sim.tsa());
	iter->set_csa (sim.csa());
	iter->set_feasible(sim.feasible());
	iter->set_partitioningfile(FLAGS_partitionFile);

	return 0;
}

void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

