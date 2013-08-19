#ifndef __CSA_HPP__
#define __CSA_HPP__


#include <task.hpp>
#include <core.hpp>
#include <vector>
#include <list>
#include <functional>
#include <algorithm>


/*! \brief CSA: Core Sorting Algorithm
 *
 */
class CSA
{
protected:
	std::vector<double> u;
	const std::vector<Core>* c;
public:
	void setCoreSet (const std::vector<Core>* cores) {
		c = cores;
	}
	void setU (const std::vector<double>& u) {
		this->u = u;
	}
	virtual bool operator()(const int a, const int b) const = 0;
	virtual void sort (std::vector<int>& cores) = 0;
};


/*
class EnergyCSA: public CSA
{
public:
	virtual bool operator()(const int a, const int b) const {
		return (*c)[a].getActive()>(*c)[b].getActive();
	}
	void sort (std::vector<int>& cores) {
		std::sort(cores.begin(), cores.end(), *this);
	}
};

class CpWCSA: public CSA
{
public:
	virtual bool operator()(const int a, const int b) const {
		double val_a = 0.0;
		double val_b = 0.0;
		for (int i=0; i<(*c)[a].getNOfResources(); i++) {
			val_a += (*c)[a].getSpeed(i);
			val_b += (*c)[b].getSpeed(i);
		}
		val_a /= (*c)[a].getActive();
		val_b /= (*c)[b].getActive();
		return val_a>val_b;
	}
	void sort (std::vector<int>& cores) {
		std::sort(cores.begin(), cores.end(), *this);
	}
};
*/


/*!
 * Sort cores in ascending order with respect to power consumption in active mode
 */
//class PowerAscCSA: public CSA
//{
//public:
//	virtual bool operator()(const int a, const int b) const {
//		return ((*c)[a].getActive())<((*c)[b].getActive());
//	}
//	void sort (std::vector<int>& cores) {
//		std::sort(cores.begin(), cores.end(), *this);
//	}
//};


/*!
 * Sort cores in descending order with respect to power consumption in active
 * mode
 */
//class PowerDescCSA: public CSA
//{
//public:
//	virtual bool operator()(const int a, const int b) const {
//		return ((*c)[a].getActive())>((*c)[b].getActive());
//	}
//	void sort (std::vector<int>& cores) {
//		std::sort(cores.begin(), cores.end(), *this);
//	}
//};


/*!
 * Sort cores in ascending order with respect to the power consumption in active
 * mode divided by the computational power
 */
//class CpWAscCSA: public CSA
//{
//public:
//	virtual bool operator()(const int a, const int b) const {
//		double val_a = 0.0;
//		double val_b = 0.0;
//		for (int i=0; i<(*c)[a].getNOfResources(); i++) {
//			val_a += (*c)[a].getSpeed(i);
//			val_b += (*c)[b].getSpeed(i);
//		}
//		val_a /= (*c)[a].getActive();
//		val_b /= (*c)[b].getActive();
//		return val_a<val_b;
//	}
//	void sort (std::vector<int>& cores) {
//		std::sort(cores.begin(), cores.end(), *this);
//	}
//};


/*!
 * Sort cores in descending order with respect to the power consumption in 
 * active mode divided by the computational power
 */
//class CpWDecCSA: public CSA
//{
//public:
//	virtual bool operator()(const int a, const int b) const {
//		double val_a = 0.0;
//		double val_b = 0.0;
//		for (int i=0; i<(*c)[a].getNOfResources(); i++) {
//			val_a += (*c)[a].getSpeed(i);
//			val_b += (*c)[b].getSpeed(i);
//		}
//		val_a /= (*c)[a].getActive();
//		val_b /= (*c)[b].getActive();
//		return val_a>val_b;
//	}
//	void sort (std::vector<int>& cores) {
//		std::sort(cores.begin(), cores.end(), *this);
//	}
//};


/*!
 * Sort cores in ascending order with respect to the computational power
 */
//class ComputationPowerFirstFitAscCSA: public CSA
//{
//public:
//	virtual bool operator()(const int a, const int b) const {
//		return (*c)[a].getSpeedSum()<(*c)[b].getSpeedSum();
//	}
//	void sort (std::vector<int>& cores) {
//		std::sort(cores.begin(), cores.end(), *this);
//	}
//};


/*!
 * Sort cores in descending order with respect to the computational power
 */
//class ComputationPowerFirstFitDescCSA: public CSA
//{
//public:
//	virtual bool operator()(const int a, const int b) const {
//		return (*c)[a].getSpeedSum()>(*c)[b].getSpeedSum();
//	}
//	void sort (std::vector<int>& cores) {
//		std::sort(cores.begin(), cores.end(), *this);
//	}
//};


/*!
 * Sort cores according to the following statement:
 * the higher the actual core utilization is, the higher the core priority is
 */
class UtilizationWorstFitCSA: public CSA
{
public:

	virtual bool operator()(const int a, const int b) const {
//		if (u[a]>u[b] ||(u[a]==u[b] && (*c)[a].getActive()<(*c)[b].getActive()))
		if (u[a]>u[b])
			return true;
		return false;
	}
	void sort (std::vector<int>& cores) {
		std::sort(cores.begin(), cores.end(), *this);
	}
};


/*!
 * Sort cores according to the following statement:
 * the higher the actual core utilization is, the lower the core priority is
 */
class UtilizationBestFitCSA: public CSA
{
public:

	virtual bool operator()(const int a, const int b) const {
//		if (u[a]<u[b] ||(u[a]==u[b] && (*c)[a].getActive()<(*c)[b].getActive()))
		if (u[a]<u[b])
			return true;
		return false;
	}
	void sort (std::vector<int>& cores) {
		std::sort(cores.begin(), cores.end(), *this);
	}
};


/*!
 * Like UtilizationWorstFitCSA, but the utilization is multiplied for the 
 * computational power
 */
//class UtilizationStarWorstFitCSA: public CSA
//{
//public:

//	virtual bool operator()(const int a, const int b) const {
//		const Core& c_a = (*c)[a];
//		const Core& c_b = (*c)[b];
//		double val_a = u[a]*c_a.getSpeedSum();
//		double val_b = u[b]*c_b.getSpeedSum();
//		if (val_a>val_b || (val_a==val_b && c_a.getActive()<c_b.getActive()))
//			return true;
//		return false;
//	}
//	void sort (std::vector<int>& cores) {
//		std::sort(cores.begin(), cores.end(), *this);
//	}
//};


/*!
 * Like UtilizationBestFitCSA, but the utilization is multiplied for the 
 * computational power
 */
//class UtilizationStarBestFitCSA: public CSA
//{
//public:

//	virtual bool operator()(const int a, const int b) const {
//		const Core& c_a = (*c)[a];
//		const Core& c_b = (*c)[b];
//		double val_a = u[a]*c_a.getSpeedSum();
//		double val_b = u[b]*c_b.getSpeedSum();
//		if (val_a<val_b || (val_a==val_b && c_a.getActive()<c_b.getActive()))
//			return true;
//		return false;
//	}
//	void sort (std::vector<int>& cores) {
//		std::sort(cores.begin(), cores.end(), *this);
//	}
//};


#endif //__ALGORITHM_HPP__

