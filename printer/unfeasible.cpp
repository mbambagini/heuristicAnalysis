/*! \file unfeasible.cpp
 *
 * Scan the final result file for extracting, for a given pair of TSA and CSA,
 * the number of unfeasibile allocations.
 * An allocation is unfeasible if one or more cores have an utilization higher
 * than the EDF scheduling bound (1.0).
 * Such information is printed on the standard output.
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

#include <results.pb.h>

#include <gflags/gflags.h>


DEFINE_string(resultsFile, "", "File containing all the results");

DEFINE_int32(TSA, 0, "TSA");
DEFINE_int32(CSA, 0, "CSA");


using namespace std;
using namespace GlobalResults;


void fatal_error (string msg);


int main (int argc, char* argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, false);
/*
	if (FLAGS_outputFile.compare("")==0)
		fatal_error ("Specify a valid output file");
*/
	GlobalResult res;
	ifstream input(FLAGS_resultsFile.c_str(), ios::in | ios::binary);
	if (!res.ParseFromIstream(&input))
		fatal_error ("Failed to parse "+FLAGS_resultsFile);
	input.close();

	int counter = 0;
	int total = 0;

	for (int i=0; i<res.results_size(); i++) {
		const GlobalResults::AlgorithmInvocation& inv = res.results(i);
		if (inv.tsa()!=FLAGS_TSA || inv.csa()!=FLAGS_CSA)
			continue;
		total++;
		if (!inv.feasible())
			counter++;
	}

	cout<<"TSA ("<<FLAGS_TSA<<"), CSA ("<<FLAGS_CSA<<"): "<<counter<<" on "<<
																	total<<endl;
	return 0;
}


void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

