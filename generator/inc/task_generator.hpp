#ifndef __TASK_GENERATOR_HPP__
#define __TASK_GENERATOR_HPP__

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <tasks.hpp>

/*! \brief task generator interface
 *
 * this generator implements the UniFast algorithm
 */
class TaskGenerator
{
	int _min;
	int _max;
	double U;
	std::vector<Task*> tasks;

	double _computeU();
	void _generate (double U, int n, int k, bool implicitModel);

	int _computeC () {
		return getMinBound() + (int)(((double)rand() / RAND_MAX) * 
											   (getMaxBound() - getMinBound()));
	}

protected:

	static bool PComp (const Task* a, const Task* b) {
		return *a < *b;
	}

	void sortTasks()
	{
		sort(tasks.begin(), tasks.end(), TaskGenerator::PComp);
	}

public:

	/*! 
	 * set computational time bound
	 */
	void setBounds (int minBound, int maxBound) {
		_min = minBound;
		_max = maxBound;
	}

	/*!
	 * get the shortest possible computation time
	 */
	int getMinBound () {
		return _min;
	}

	/*!
	 * get the longest possible computation time
	 */
	int getMaxBound () {
		return _max;
	}

	/*!
	 * generate a task set
	 *
	 * \param U desired utilization
	 * \param n number of tasks
	 * \param k number of resources
	 * \param implicitModel implicit model?
	 */
	virtual void generate (double U, int n, int k, bool implicitModel);

	/*!
	 * return the actual utilization
	 */
	double getU () {
		U = _computeU();
		return U;
	}

	/*!
	 * task number
	 */
	int getNumber () {
		return tasks.size();
	}

	/*!
	 * get the id-th task 
	 */
	const Task& operator[] (int id) const {
		return *(tasks[id]);
	}

};

#endif // __TASK_GENERATOR_HPP__

