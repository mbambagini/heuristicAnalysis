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


DEFINE_string(resultsFile, "", "File containing all the results");


using namespace std;
using namespace GlobalResults;


void fatal_error (string msg);


int main (int argc, char* argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, false);

	GlobalResult res;
	ifstream input(FLAGS_resultsFile.c_str(), ios::in | ios::binary);
	if ((bool)input) {
		if (!res.ParseFromIstream(&input))
			fatal_error ("Failed to parse "+FLAGS_resultsFile);
	}
	input.close();

	for (int i=0; i<res.results_size(); i++) {
		const GlobalResults::AlgorithmInvocation& inv = res.results(i);
		cout<<"---------------------------------------------------------"<<endl;
		cout<<"TSA ("<<inv.tsa()<<"), CSA ("<<inv.csa()<<")"<<endl;
		cout<<"#cores ("<<inv.nofcores()<<")"<<endl;
		cout<<"nominal utilization ("<<inv.u()<<")"<<endl;
		cout<<setw(10)<<"CORE"<<setw(15)<<"U"<<setw(10)<<"#TASKS"<<setw(20);
		if (!inv.feasible())
			continue;
		cout<<"MEAN POWER"<<endl;
		for (int j=0; j<inv.cons_size(); j++) {
			const GlobalResults::Consumption& c = inv.cons(j);
			cout<<setw(10)<<c.core()<<setw(15)<<c.u();
			cout<<setw(10)<<c.noftasks()<<setw(20)<<c.meanp()<<endl;
		}
		cout<<endl;
	}
	return 0;
}


void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

