#ifndef __CORE_HPP__
#define __CORE_HPP__


#include <vector>


class Core
{
/*
	double Pidle;
	double Psleep;
	double Pactive;
	double Pswitching;
	int bet;
*/

	std::vector<int> resourcesPerSecond;

public:

/******************************************************************************
 ***************************** INFORMATION SETTING ****************************
 ******************************************************************************/

	/*! Power consumption during idle */
//	void setIdle (double p) {
//		Pidle = p;
//	}

	/*! Power consumption during sleep */
//	void setSleep (double p) {
//		Psleep = p;
//	}

	/*! Power consumption during active state */
//	void setActive (double p) {
//		Pactive = p;
//	}

	/*! Power consumption during switching mode */
//	void setSwitch (double p) {
//		Pswitching = p;
//	}

	/*! Break-even time */
//	void setBET (int bet) {
//		this->bet = bet;
//	}

	/*! Number of computational elements */
	void setNOfResources (int n) {
		resourcesPerSecond.resize(n);
	}

	/*!
	 * in this context, speed means the amount of computational units of the 
	 * specified resource that the core can execute for each time unit
	 */
	void setResPerSec (int resource, int numPerSec) {
		resourcesPerSecond[resource] = numPerSec;
	}


/******************************************************************************
 **************************** INFORMATION RETREIVAL ***************************
 ******************************************************************************/

	/*! Number of computational elements */
	int getNOfResources () const {
		return resourcesPerSecond.size();
	}

	/*!
	 * \see setResPerSec
	 */
	int getResPerSec (int resource) const {
		return resourcesPerSecond[resource];
	}

	/*! Parameter representing the computational power */
	int getResPerSec() const {
		int sum = 0;
		for (unsigned int i=0; i<resourcesPerSecond.size(); i++)
			sum += resourcesPerSecond[i];
		return sum;
	}

	/*! Power consumption during idle */
//	double getIdle () const {
//		return Pidle;
//	}

	/*! Power consumption during sleep */
//	double getSleep () const {
//		return Psleep;
//	}

	/*! Power consumption during active state */
//	double getActive () const {
//		return Pactive;
//	}

	/*! Power consumption during switching mode */
//	double getSwitch () const {
//		return Pswitching;
//	}

	/*! Break-even time */
//	int getBET () const {
//		return bet;
//	}

};


#endif //__CORE_HPP__

