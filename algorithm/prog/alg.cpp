#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <tsa.hpp>
#include <csa.hpp>
#include <heuristic.hpp>
#include <serializer_protobuf.hpp>
#include <gflags/gflags.h>
#include <problem.pb.h>

DEFINE_string(hardwareFile, "", "Input file with hardware information");
DEFINE_string(softwareFile, "", "Input file with software information");
DEFINE_string(dstFolder, "", "Destination folder");
DEFINE_int32(CSA, 0, "Core Sorting Algorithm");
DEFINE_int32(TSA, 0, "Task Sorting Algorithm");

using namespace std;

void fatal_error (string msg);

int main (int argc, char* argv[])
{

	GOOGLE_PROTOBUF_VERIFY_VERSION;
	google::ParseCommandLineFlags(&argc, &argv, false);

	/*
	 * Parameter check and object creation
	 */
	if (FLAGS_hardwareFile.compare("")==0 || FLAGS_softwareFile.compare("")==0)
		fatal_error("The problem files are both mandatory");
	Problem::Software sw;
	fstream i_s(FLAGS_softwareFile.c_str(), ios::in | ios::binary);
	if (!sw.ParseFromIstream(&i_s))
		fatal_error("Failed to parse sw file");
	Problem::Hardware h;
	fstream i_h(FLAGS_hardwareFile.c_str(), ios::in | ios::binary);
	if (!h.ParseFromIstream(&i_h))
		fatal_error("Failed to parse hw file");
	if (h.nofresources()!=sw.units())
		fatal_error("Number of resources mismatch");

	TSA* tsa;
	switch (FLAGS_TSA) {
		case 0: tsa = new UtilizationAscTSA(); break;
		case 1: tsa = new UtilizationDescTSA(); break;
		case 2: tsa = new SlackAscTSA(); break;
		case 3: tsa = new SlackDescTSA(); break;
		default:
			fatal_error("Invalid TSA");
	}
	CSA* csa;
	switch (FLAGS_CSA) {
		case 0: csa = new PowerAscCSA(); break;
		case 1: csa = new PowerDescCSA(); break;
		case 2: csa = new CpWAscCSA(); break;
		case 3: csa = new CpWDecCSA(); break;
		case 4: csa = new ComputationPowerFirstFitAscCSA(); break;
		case 5: csa = new ComputationPowerFirstFitDescCSA(); break;
		case 6: csa = new UtilizationWorstFitCSA(); break;
		case 7: csa = new UtilizationBestFitCSA(); break;
		case 8: csa = new UtilizationStarWorstFitCSA(); break;
		case 9: csa = new UtilizationStarBestFitCSA(); break;
		default:
			fatal_error("Invalid CSA");
	}
	Heuristic alg(tsa, csa);
	if (!alg.read(sw, h))
		fatal_error("Impossible to read problem");
	vector<int> a;
	vector<double> u;

	/*
	 * Execution
	 */
	bool feasible = alg.run(a, u);
	if (!feasible)
		cout<<"Not feasible"<<endl;
	SerializerProtobuf ser;
	ser.setHardware(&h);
	ser.setSoftware(&sw);
	ser.setAllocation(a);
	ser.setUtilization(u);
	for (unsigned int i=0; i<u.size(); i++) {
		stringstream sstream;
		sstream<<FLAGS_dstFolder<<"/"<<FLAGS_CSA<<"-"<<FLAGS_TSA<<"-";
		sstream<<i<<".bin";
		ser.serialize(sstream.str(), i, feasible);
	}
	return 0;
}

void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

