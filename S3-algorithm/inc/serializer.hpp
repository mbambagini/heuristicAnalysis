#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__


#include <string>
#include <vector>

#include <heuristic.hpp>
#include <problem.pb.h>

/*! \brief Serialization class
 *
 * This class is in charge of serializing the information related to the tasks
 * assigned to the specified core
 */
class Serializer
{

	const Problem::Software* sw;
	const Problem::Hardware* hw;

	std::vector<int> a;
	std::vector<double> u;

protected:

	const Problem::Software* getSw () {
		return sw;
	}
	const Problem::Hardware* getHw () {
		return hw;
	}

	int getAllocation (int taskId) {
		return a[taskId];
	}

	double getUtilization (int coreId) {
		return u[coreId];
	}

public:

	Serializer (): sw(NULL), hw(NULL) {}

	void setSoftware (const Problem::Software* sw) {
		this->sw = sw;
	}

	void setHardware (const Problem::Hardware* hw) {
		this->hw = hw;
	}

	void setUtilization (std::vector<double> u) {
		this->u = u;
	}
	void setAllocation (std::vector<int> a) {
		this->a = a;
	}

	virtual bool serialize (const std::string& file, bool feas, int csa,
																int tsa) = 0;

};



#endif //__SERIALIZER_HPP__

