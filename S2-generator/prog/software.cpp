/*! \file software.cpp
 *  \brief generate the software testbed
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <randomizer.hpp>
#include <task_generator.hpp>
#include <problem.pb.h>
#include <gflags/gflags.h>


using namespace std;


DEFINE_string(binaryFile, "", "Binary file");

DEFINE_int32(maxBound, 1000, "Maximum bound");
DEFINE_int32(minBound, 100, "Minimum bound");

DEFINE_int32(numRes, 2, "Number of resources");

DEFINE_int32(n, 10, "task number");

DEFINE_double(u, 0.9, "utilization");

DEFINE_int32(seed, 0, "Seed");
#define MAX_SEED 32767.


void fatal_error (string msg);


int main (int argc, char* argv[])
{
	//check parameters
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	google::ParseCommandLineFlags(&argc, &argv, false);

	if (FLAGS_binaryFile.compare("")==0)
		fatal_error("the output file is mandatory");
	if (FLAGS_numRes<1)
		fatal_error("the resource number must be greater than 0");

	//generation process
	Problem::Software sw;
	sw.set_nofresources(FLAGS_numRes);

	double seed = (double)time(0);
	seed *= FLAGS_seed;
	seed /= MAX_SEED;
	srand(seed);

	TaskGenerator gen;
	gen.setBounds(FLAGS_minBound, FLAGS_maxBound);
	double real_u;
	do {
		gen.generate(FLAGS_u, FLAGS_n, FLAGS_numRes, true);
		real_u = gen.getU();
	} while(real_u>FLAGS_u || real_u<(FLAGS_u*0.9));

	sw.set_u(FLAGS_u);
	sw.set_real_u(real_u);
	for (int j=0; j<FLAGS_n; j++) {
		Problem::Task *t = sw.add_tasks();
		t->set_id(j);
		t->set_wcet(gen[j].getC());
		for (int k=0; k<FLAGS_numRes; k++)
			t->add_wcets(gen[j].getC(k));
		t->set_period(gen[j].getT());
		t->set_deadline(gen[j].getD());
	}

	//output - serialization
	fstream output(FLAGS_binaryFile.c_str(), ios::out|ios::trunc|ios::binary);
	if (!sw.SerializeToOstream(&output))
		fatal_error("failed to serialize");
	output.close();

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}


void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

