#include <simulations.pb.h>
#include <serializer_protobuf.hpp>

#include <math.h>
#include <fstream>


using namespace std;


bool SerializerProtobuf::serialize (const std::string& file, int core,
																	  bool feas)
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	Simulations::Simulation sim;

	Problem::ProcessorType type =
						  getHardware()->types(getHardware()->processors(core));

	sim.set_core(core);
	sim.set_utilization(getUtilization(core));
	sim.set_bet(type.bet());

	sim.set_feasible(feas);
/*
	for (int i=0; (i<getSoftware()->tasks_size())&&sim.feasible(); i++)
		if (getAllocation(i)==-1)
			sim.set_feasible(false);
*/

	for (int i=0; (i<getHardware()->processors_size())&&sim.feasible(); i++)
		if (getUtilization(i)>1.0)
			sim.set_feasible(false);

	for (int i=0; i<getSoftware()->tasks_size(); i++)
		if (getAllocation(i)==core) {
			Simulations::Task* t = sim.add_tasks();
			t->set_id(getSoftware()->tasks(i).id());
			t->set_period(getSoftware()->tasks(i).period());
			t->set_deadline(getSoftware()->tasks(i).deadline());
			int tmp = 0;
			for (int j=0; j<getHardware()->nofresources(); j++)
				tmp += trunc((double)(getSoftware()->tasks(i).wcets(j))/
															   (type.speed(j)));
			t->set_wcet(tmp);
		}

	//output - serialization
	fstream output(file.c_str(), ios::out|ios::trunc|ios::binary);
	if (!sim.SerializeToOstream(&output))
		return false;
	output.close();

	google::protobuf::ShutdownProtobufLibrary();

	return true;
}

