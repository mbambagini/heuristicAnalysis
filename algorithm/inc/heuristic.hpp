#ifndef __HEURISTIC_HPP__
#define __HEURISTIC_HPP__

#include <vector>
#include <list>
#include <string>

#include <task.hpp>
#include <core.hpp>
#include <tsa.hpp>
#include <csa.hpp>

#include <problem.pb.h>


/*! \brief heuristic body structure 
 *
 * This class contains the skeltron of the partitioning algorithm as
 * the features that differentiate the heuristics are deletegated to other
 * classes as stated from the strategy pattern.
 */
class Heuristic
{

protected:

	std::vector<Task> tasks;
	std::vector<Core> cores;

	void sortCores(const std::vector<double>& u, std::vector<int>& l);
	void sortTasksPerCore (std::vector< std::list<int> >& tl);

	TSA* taskSorter;
	CSA* coreSorter;

	bool _feasible;

public:

	/*!
	 * Set the Task Sorting Algorithm (TSA) and Core Sorting Algorothm (CSA)
	 */
	Heuristic (TSA* t, CSA* c) {
		taskSorter = t;
		coreSorter = c;
		_feasible = false;
	}

	/*!
	 * Read the software and hardware information to use
	 */
	bool read (const Problem::Software& s, const Problem::Hardware& h);

	/*!
	 * Execute the partitioning algorithm
	 */
	int run (std::vector<int>& a, std::vector<double>& u);

	/*!
	 * Return whether the resulting partition is feasible or not
	 */
	bool feasible() {
		return _feasible;
	}

#ifdef DEBUG
	void print ();
#endif //DEBUG

	virtual ~Heuristic() {};
};

#endif //__HEURISTIC_HPP__

