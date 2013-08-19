#include <task_generator.hpp>
#include <tasks.hpp>

#include <math.h>
#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>

using namespace std;


double TaskGenerator::_computeU ()
{
	double U = 0.0;

	for (unsigned int i=0; i<tasks.size(); i++)
		U += (double)(tasks[i]->getC())/(tasks[i]->getT());
	return U;
}


void TaskGenerator::_generate (double U, int n, int k, bool implicitModel)
{
	double Usum = U;

	tasks.resize(n);
	for (int i = 0; i<n-1; i++) {
		int C = _computeC();
		double Unext = Usum * pow((double)rand() / RAND_MAX, (1.0/(n-i)));
		int T = ceil((double)C / (Usum - Unext));
		int D = implicitModel? T:fmax(C,T/2+(int)((double)T/2*rand()/RAND_MAX));
		if (((double)C/T)>1.0) {
			i--;
			continue;
		}
		Usum = Unext;
		tasks[i] = new Task(k, C, D, T);
		int val = C;
		for (int i_k=0; i_k<(k-1); i_k++) {
			int c_i = (double)val*((double)rand()/RAND_MAX);
			tasks[i]->write(i_k, c_i);
			val -= c_i;
		}
		tasks[i]->write(k-1, val);
  	}
	double Unext = Usum>1.0?Usum-1.0:0.0;
	int C = _computeC();   
	int T = ceil((double)C / (Usum-Unext));
	int D = implicitModel? T : C + (int)((double)(T - C) * rand() / RAND_MAX);
	tasks[n-1] = new Task(k, C, D, T);
	int val = C;
	for (int i_k=0; i_k<(k-1); i_k++) {
		int c_i = (double)val*((double)rand()/RAND_MAX);
		tasks[n-1]->write(i_k, c_i);
		val -= c_i;
	}
	tasks[n-1]->write(k-1, val);
	Usum = Unext;
	while (Usum>0.0) {
		int id = rand()%n;
		double u = (double)(tasks[id]->getC())/tasks[id]->getT();
		int C = _computeC();
		double new_u = min(1.0-u, Usum) * pow((double)rand() / RAND_MAX, (1.0/id));
		Usum -= new_u;
		u += new_u;
		int T = ceil((double)C / u);
		int D = implicitModel? T:fmax(C,T/2+(int)((double)T/2*rand()/RAND_MAX));
		tasks[id] = new Task(k, C, D, T);
		int val = C;
		for (int i_k=0; i_k<(k-1); i_k++) {
			int c_i = (double)val*((double)rand()/RAND_MAX);
			tasks[id]->write(i_k, c_i);
			val -= c_i;
		}
		tasks[id]->write(k-1, val);
	}
}


void TaskGenerator::generate (double U, int n, int k, bool implicitModel)
{
	double tmp_U;
	do {
		_generate(U, n, k, implicitModel);
		tmp_U = getU();
	} while(tmp_U>U);
	sortTasks();
}

