#ifndef __TASKS_HPP__
#define __TASKS_HPP__

#include <stdlib.h>

#include <math.h>
#include <algorithm>
#include <vector>



/*! \Basic task description
 *
 */
class Task {
private:
	int C_tot;
	std::vector<int> C;
	int D;
	int T;

public:

	/*!
	 * \param n number of resources
	 * \param C overall computation time on a core with unitary computation
	 *			power for each resource
	 */
	Task (int n, int C, int D, int T) {
		this->C_tot = C;
		this->D = D;
		this->T = T;
		this->C.resize(n);
	}

	void write (int i, int c) {
		C[i] = c;
	}

	int getC () const {
		return C_tot;
	}

	int getC (int i) const {
		return C[i];
	}

	int getD () const {
		return D;
	}

	int getT () const {
		return T;
	}

	/*!
	 * Task sorting according to the deadline
	 */
	bool operator< (Task const& a) const {
		return D<a.getD();
	}
};


#endif // __TASKS_HPP__

