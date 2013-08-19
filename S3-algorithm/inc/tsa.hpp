#ifndef __TSA_HPP__
#define __TSA_HPP__


#include <task.hpp>
#include <core.hpp>
#include <vector>
#include <list>
#include <functional>
#include <algorithm>


/*! \brief TSA: Task Sorting Algorithm
 *
 */
class TSA
{
protected:
	const std::vector<Task>* t;
//	int core;
public:
	void setTaskSet (const std::vector<Task>* set) {
		t = set;
	}
//	void setCore (int core) {
//		this->core = core;
//	}

	virtual bool operator()(const int a, const int b) const = 0;

	virtual void sort (std::list<int>& l) = 0;
};


/*!
 * Sort tasks from lowest to highest utilization on a specified core
 */
class UtilizationAscTSA: public TSA
{
public:
	bool operator()(const int a, const int b) const {
//		double u_a = (double)(*t)[a].getC(core)/(*t)[a].getT();
//		double u_b = (double)(*t)[b].getC(core)/(*t)[b].getT();
		double u_a = (double)(*t)[a].getC()/(*t)[a].getT();
		double u_b = (double)(*t)[b].getC()/(*t)[b].getT();
		return u_a<u_b;
	}

	void sort (std::list<int>& l) {
		l.sort(*this);//std::mem_fun( &UtilizationTSA::operator() ) );
	}
};


/*!
 * sort tasks from highest to lowest utilization on a specified core
 */
class UtilizationDescTSA: public TSA
{
public:
	bool operator()(const int a, const int b) const {
//		double u_a = (double)(*t)[a].getC(core)/(*t)[a].getT();
//		double u_b = (double)(*t)[b].getC(core)/(*t)[b].getT();
		double u_a = (double)(*t)[a].getC()/(*t)[a].getT();
		double u_b = (double)(*t)[b].getC()/(*t)[b].getT();
		return u_a>u_b;
	}

	void sort (std::list<int>& l) {
		l.sort(*this);
	}
};


/*!
 * Sort tasks from lowest to highest T-C
 */
//class SlackAscTSA: public TSA
//{
//public:
//	bool operator()(const int a, const int b) const {
//		int slack_a = (*t)[a].getT()-(*t)[a].getC(core);
//		int slack_b = (*t)[b].getT()-(*t)[b].getC(core);
//		return slack_a<slack_b;
//	}
//	void sort (std::list<int>& l) {
//		l.sort(*this);
//	}
//};


/*!
 * Sort tasks from highest to lowest T-C
 */
//class SlackDescTSA: public TSA
//{
//public:
//	bool operator()(const int a, const int b) const {
//		int slack_a = (*t)[a].getT()-(*t)[a].getC(core);
//		int slack_b = (*t)[b].getT()-(*t)[b].getC(core);
//		return slack_a>slack_b;
//	}
//	void sort (std::list<int>& l) {
//		l.sort(*this);
//	}
//};


#endif //__TSA_HPP__

