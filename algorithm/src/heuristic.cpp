#include <heuristic.hpp>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>



using namespace std;



bool Heuristic::read (const Problem::Software& s, const Problem::Hardware& h)
{
	tasks.resize(s.tasks_size());
	cores.resize(h.processors_size());

	//software
	for (int i=0; i<s.tasks_size(); i++) {
		const Problem::Task t = s.tasks(i);
		tasks[i].setD(t.deadline());
		tasks[i].setT(t.period());
		tasks[i].setNOfCores(h.processors_size());
		for (int j=0; j<h.processors_size(); j++) {
			const Problem::ProcessorType& type = h.types(h.processors(j));
			double c = 0.0;
			for (int k=0; k<t.wcets_size(); k++)
				c += (double) (t.wcets(k)) / type.speed(k);
			tasks[i].setC(trunc(c), j);
		}
	}

	//hardware
	for (int i=0; i<h.processors_size(); i++) {
		const Problem::ProcessorType& t = h.types(h.processors(i));
		cores[i].setIdle(t.pidle());
		cores[i].setSleep(t.psleep());
		cores[i].setActive(t.pactive());
		cores[i].setSwitch(t.pswitching());
		cores[i].setBET(t.bet());
		cores[i].setNOfResources(t.speed_size());
		for (int j=0; j<t.speed_size(); j++)
			cores[i].setSpeed(j, t.speed(j));
	}

	return true;
}



int Heuristic::run (std::vector<int>& a, std::vector<double>& u)
{
	_feasible = true;
	a.resize(tasks.size());
	for (unsigned int i=0; i<a.size(); i++)
		a[i] = -1;
	u.resize(cores.size());
	for (unsigned int i=0; i<u.size(); i++)
		u[i] = 0.0;

	std::vector<std::list<int> > ordered_tasks_per_core;
	sortTasksPerCore(ordered_tasks_per_core);
	bool stop = false;

	while (!stop && _feasible) {
		std::vector<int> sorted_cores(u.size());
		sortCores(u, sorted_cores);
		_feasible = false;
		for (std::vector<int>::iterator it=sorted_cores.begin();
												 it!=sorted_cores.end(); it++) {
			int c = *it;
			int t = ordered_tasks_per_core[c].front();
			double u_t = (double)(tasks[t].getC(c))/tasks[t].getT();
			if ((u[c]+u_t)>1.0)
				continue;
			u[c] += u_t;
			a[t] = c;
			ordered_tasks_per_core[c].pop_front();
			_feasible = true;
			for (unsigned int i=0; i<ordered_tasks_per_core.size(); i++)
				ordered_tasks_per_core[i].remove(t);
			if (ordered_tasks_per_core[c].empty())
				stop = true;
			break;
		}
	}

	for (unsigned int i=0; i<a.size()&&_feasible; i++)
		if (a[i]==-1)
			_feasible = false;
	for (unsigned int i=0; i<u.size()&&_feasible; i++)
		if (u[i]>1.0 || u[i]<0.0)
			_feasible = false;

	return _feasible;
}



void Heuristic::sortCores (const std::vector<double>& u, std::vector<int>& l)
{
//	l.resize(u.size());
	coreSorter->setU(u);
	coreSorter->setCoreSet(&cores);
	for (unsigned int i=0; i<u.size(); i++)
		l[i] = i;
	coreSorter->sort(l);
}



void Heuristic::sortTasksPerCore (std::vector<std::list<int> >& tl)
{
	tl.resize(cores.size());
	for (unsigned int i=0; i<cores.size(); i++) {
		taskSorter->setCore(i);
		taskSorter->setTaskSet(&tasks);
		for (unsigned int j=0; j<tasks.size(); j++)
			tl[i].push_front(j);
		taskSorter->sort(tl[i]);
	}
}



#ifdef DEBUG
void Heuristic::print ()
{
	cout<<"-------------------------------------------------------------"<<endl;

	//software
	cout<<setw(10)<<"D"<<setw(10)<<"T";
	for (unsigned int j=0; j<cores.size(); j++)
		cout<<setw(10)<<"C_"<<j;
	cout<<endl;
	for (unsigned int i=0; i<tasks.size(); i++) {
		cout<<setw(10)<<tasks[i].getD()<<setw(10)<<tasks[i].getT();
		for (unsigned int j=0; j<cores.size(); j++)
			cout<<setw(10)<<tasks[i].getC(j);
		cout<<endl;
	}
	cout<<endl;

	//hardware
	cout<<setw(10)<<"Pidle"<<setw(10)<<"Psleep"<<setw(10)<<"Pactive";
	cout<<setw(10)<<"Pswitch"<<setw(10)<<"BET"<<endl;
	for (unsigned int i=0; i<cores.size(); i++) {
		cout<<setw(10)<<cores[i].getIdle()<<setw(10)<<cores[i].getSleep();
		cout<<setw(10)<<cores[i].getActive()<<setw(10)<<cores[i].getSwitch();
		cout<<setw(10)<<cores[i].getBET()<<endl;
	}
	cout<<endl;
}
#endif //DEBUG

