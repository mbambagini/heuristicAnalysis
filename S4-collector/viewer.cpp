/*! \file viewer.cpp
 * 
 * Print the aggregated results on the standard output.
 * More pricisely, for each simulation the program prints the mean power
 * consumption of each deployed core.
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


DEFINE_string(srcFile, "", "File containing all the results");


using namespace std;
using namespace Results;


void fatal_error (string msg);


int main (int argc, char* argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, false);

	Result res;
	ifstream input(FLAGS_srcFile.c_str(), ios::in | ios::binary);
	if ((bool)input) {
		if (!res.ParseFromIstream(&input))
			fatal_error ("Failed to parse "+FLAGS_srcFile);
	}
	input.close();

	cout<<"hardware file: "<<res.hwfile()<<endl<<endl;
	for (int i=0; i<res.iterations_size(); i++) {
		const Execution& iter = res.iterations(i);
		cout<<"---------------------------------------------------------"<<endl;
		cout<<"Problem "<<i<<" (n: "<<iter.n()<<", u: "<<iter.u()<<")"<<endl;
		cout<<"TSA: "<<iter.tsa()<<", CSA: "<<iter.csa()<<endl;
		cout<<"no sfa: "<<iter.no_sfa().meanpower()<<endl;
		for (int j=0; j<iter.sfa_size(); j++)
			cout<<"alpha: "<<iter.sfa(j).alpha()<<", power: "<<
												  iter.sfa(j).meanpower()<<endl;
	}
	return 0;
}


void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

