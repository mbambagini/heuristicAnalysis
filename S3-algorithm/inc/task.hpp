#ifndef __TASK_HPP__
#define __TASK_HPP__


#include <vector>


class Task
{

	int D;
	int T;
//	std::vector<int> C;
	int C;

public:

/******************************************************************************
 ***************************** INFORMATION SETTING ****************************
 ******************************************************************************/

	/*!
	 * Number of cores
	 */
//	void setNOfCores (int n) {
//		C.resize(n);
//	}
	void setC (int C) {
		this->C = C;
	}


	/*!
	 * Deadline
	 */
	void setD (int D) {
		this->D = D;
	}

	/*!
	 * Period
	 */
	void setT (int T) {
		this->T = T;
	}

	/*!
	 * Computation time on the specified core
	 */
//	void setC (int C, int core) {
//		this->C[core] = C;
//	}



/******************************************************************************
 **************************** INFORMATION RETREIVAL ***************************
 ******************************************************************************/

	/*!
	 * Deadline
	 */
	int getD () const {
		return D;
	}

	/*!
	 * Period
	 */
	int getT () const {
		return D;
	}

	/*!
	 * Computation time on the specified core
	 */
//	int getC (int core) const {
//		return C[core];
//	}

	int getC () const {
		return C;
	}

};


#endif //__TASK_HPP__

