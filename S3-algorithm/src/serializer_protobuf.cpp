#include <simulations.pb.h>
#include <serializer_protobuf.hpp>

#include <math.h>
#include <fstream>


using namespace std;


bool SerializerProtobuf::serialize (const std::string& file, bool feas,	int csa, int tsa)
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	Simulations::Simulation sim;

//	Problem::ProcessorType type =
//						  getHardware()->types(getHardware()->processors(core));

//	sim.set_core(core);
//	sim.set_utilization(getUtilization(core));
//	sim.set_bet(type.bet());

	sim.set_csa(csa);
	sim.set_tsa(tsa);
	sim.set_feasible(feas);
/*
	for (int i=0; (i<getSoftware()->tasks_size())&&sim.feasible(); i++)
		if (getAllocation(i)==-1)
			sim.set_feasible(false);
*/

	for (int i=0; i<(getHw()->nofclusters()*getHw()->cpc()); i++)
		if (getUtilization(i)>1.0) {
			sim.set_feasible(false);
			break;
		}

	int res = 0;
	for (int i=0; i<getHw()->nofresources(); i++)
		res += getHw()->resources(i);

	for (int i=0; i<getSw()->tasks_size(); i++) {
		Simulations::Task* t = sim.add_tasks();
		t->set_id(getSw()->tasks(i).id());
		t->set_period(getSw()->tasks(i).period());
		t->set_deadline(getSw()->tasks(i).deadline());
		int C = 0;
		for (int j=0; j<getHw()->nofresources(); j++)
			C += getSw()->tasks(i).wcets(j);
		t->set_wcet(trunc((double)C/res));
		t->set_core(getAllocation(i));
//		int tmp = 0;
//		for (int j=0; j<getHardware()->nofresources(); j++)
//			tmp += trunc((double)(getSoftware()->tasks(i).wcets(j))/
//														   (type.speed(j)));
//		t->set_wcet(tmp);
	}

	int nOfCores = getHw()->nofclusters()*getHw()->cpc();
	for (int i=0; i<nOfCores; i++) {
		Simulations::Core* c = sim.add_cores();
		c->set_id(i);
		c->set_u(getUtilization(i));
	}


	//output - serialization
	fstream output(file.c_str(), ios::out|ios::trunc|ios::binary);
	if (!sim.SerializeToOstream(&output))
		return false;
	output.close();

	google::protobuf::ShutdownProtobufLibrary();

	return true;
}

