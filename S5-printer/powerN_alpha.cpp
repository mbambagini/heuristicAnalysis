/*! \file powerN.cpp
 *
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

DEFINE_double(u_min, 10, "");
DEFINE_double(u_max, 10, "");

DEFINE_int32(n_min, 0.0, "");
DEFINE_int32(n_step, 0.0, "");
DEFINE_int32(n_max, 10.0, "");

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
	int n = ceil((FLAGS_n_max-FLAGS_n_min)/FLAGS_n_step)+1;
	std::vector<t_power> p_no_sfa(n);
	std::vector<std::vector<t_power> > p_sfa(11);
	for (int j=0; j<11; j++)
		p_sfa[j].resize(n);
	for (int nt=FLAGS_n_min; nt<=FLAGS_n_max; nt+=FLAGS_n_step) {
		for (int j=0; j<res.iterations_size(); j++) {
			const Results::Execution& inv = res.iterations(j);
			if (inv.u()<=FLAGS_u_max && inv.u()>FLAGS_u_min &&
								 inv.csa()==FLAGS_csa && inv.feasible() && inv.n()==nt){
				p_no_sfa[i].add(inv.no_sfa().meanpower());
				for (int k=0; k<inv.sfa_size(); k++) {
					int index = round(inv.sfa(k).alpha()*10);
					p_sfa[index][i].add(inv.sfa(k).meanpower());
				}
			}
		}
		i++;
	}
	i = 0;
	for (int j=FLAGS_n_min; j<=FLAGS_n_max; j+=FLAGS_n_step) {
		cout<<setprecision(8);
		cout<<j<<setw(15)<<p_no_sfa[i].getP();
		for (int k=0; k<11; k++)
			cout<<setw(15)<<p_sfa[k][i].getP();
		cout<<endl;
		i++;
	}
}

