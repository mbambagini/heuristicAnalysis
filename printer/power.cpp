/*! \file power.cpp
 *
 * Scan the final result file to compute, for each utilization step, the average
 * power consumption required from a given algorithm pair (TSA and CSA).
 * Information about consumption is printed on the standard output
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


/*!
 * This class is in charge of getting a consumption entry (U and power) and
 * account the consumption to the relative utilization.
 * At the end, this element will contains a set of utilization points and the
 * relative mean consumptions.
 */
class PowerContainer
{
	struct accounter {
		double power;
		int num;
		double u;
		accounter(double u) {
			power = 0.0;
			num = 0;
			this->u = u;
		}
		accounter(double u, double p) {
			power = p;
			num = 1;
			this->u = u;
		}
	};

	list<accounter> l;
	list<accounter>::const_iterator i;

public:

	/*!
	 * add a pair U:power
	 */
	void add (double u, double power);

	/*!
	 * move the data structures to the lowest utilization element (first)
	 */
	bool first () {
		i = l.begin();
		return l.size()!=0;
	}

	/*!
	 * move to the next utilization step
	 */
	bool next () {
		i++;
		if (i==l.end())
			return false;
		return true;
	}

	/*!
	 * get the actual utilization
	 */
	double getU () {
		return i->u;
	}

	/*!
	 * get the actual consumption
	 */
	double getP () {
		return i->power/i->num;
	}
};


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

	PowerContainer container;

	for (int i=0; i<res.results_size(); i++) {
		const GlobalResults::AlgorithmInvocation& inv = res.results(i);
		if (!inv.feasible() || inv.tsa()!=FLAGS_TSA || inv.csa()!=FLAGS_CSA)
			continue;
		for (int j=0; j<inv.cons_size(); j++)
			container.add(inv.u(), inv.cons(j).meanp());
	}
	if (container.first())
		do {
			cout<<container.getU()<<"\t"<<container.getP()<<endl;
		} while (container.next());
	return 0;
}


void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}


void PowerContainer::add (double u, double power)
{
	for (list<accounter>::iterator it = l.begin(); it!=l.end(); it++) {
		if ((it->u-u)<0.0001 && (it->u-u)>-0.0001) {
			it->power += power;
			it->num++;
			return;
		}
	}
	l.push_back(accounter(u, power));
}

