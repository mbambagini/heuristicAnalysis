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
#include <math.h>

#include <results.pb.h>

#include <gflags/gflags.h>


DEFINE_string(srcFile, "", "");
//DEFINE_string(outFile, "", "");

DEFINE_int32(n, 10, "");

DEFINE_double(u_min, 0.0, "");
DEFINE_double(u_step, 0.0, "");
DEFINE_double(u_max, 10.0, "");

DEFINE_int32(csa, 0, "");
DEFINE_int32(tsa, 0, "");

using namespace std;
using namespace Results;


void fatal_error (string msg);

void parse (const Result& res);


int main (int argc, char* argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, false);

//	if (FLAGS_outFile.compare("")==0)
//		fatal_error ("Specify a valid output file");

	Result res;
	ifstream input(FLAGS_srcFile.c_str(), ios::in | ios::binary);
	if (!res.ParseFromIstream(&input))
		fatal_error ("Failed to parse "+FLAGS_srcFile);
	input.close();

	parse(res);

	return 0;
}



void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}


struct t_power {
	double sum;
	int n;
	t_power () {
		sum = 0.0;
		n = 0;
	}
	void add (double p) {
		sum += p;
		n++;
	}
	double getP () {
		return n==0?0.0:sum/n;
	}
};


void parse (const Result& res)
{
	int i = 0;
	int n = ceil((FLAGS_u_max-FLAGS_u_min)/FLAGS_u_step)+1;
	std::vector<t_power> p_sfa(n);
	std::vector<t_power> p_no_sfa(n);
	double u = FLAGS_u_min;
	while (u<=FLAGS_u_max) {
		for (int j=0; j<res.iterations_size(); j++) {
			const Results::Execution& inv = res.iterations(j);
			if (inv.u()<=u && inv.u()>(u-FLAGS_u_step) && inv.csa()==FLAGS_csa &&
											inv.feasible() && inv.n()==FLAGS_n){
				p_no_sfa[i].add(inv.no_sfa().meanpower());
				for (int k=0; k<inv.sfa_size(); k++)
					if (inv.sfa(k).alpha()<0.1)
						p_sfa[i].add(inv.sfa(k).meanpower());
			}
		}
		u += FLAGS_u_step;
		i++;
	}
	u = FLAGS_u_min;
	for (int i=0; i<n; i++) {
		cout<<setprecision(8);
		cout<<setw(15)<<u<<setw(15)<<p_no_sfa[i].getP()<<setw(15);
		cout<<p_sfa[i].getP()<<endl;
		u += FLAGS_u_step;
	}
}

