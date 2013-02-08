#include <fstream>
#include <iostream>
#include <iomanip>

#include <software_printer.hpp>

#include <problem.pb.h>

using namespace std;

int SoftwarePrinter::serialize (ostream& out, Problem::Software& sw)
{
	out<<"#Resources:\t\t"<<sw.units()<<endl;
	out<<"Utilization: "<<sw.u()<<endl<<endl;

	out<<"Tasks:"<<endl;
	out<<setw(10)<<"ID"<<setw(10)<<"C"<<setw(10)<<"T"<<setw(10)<<"D";
	out<<setw(10)<<"C_i"<<endl;
	for (int j=0; j<sw.tasks_size(); j++) {
		const Problem::Task t = sw.tasks(j);
		out<<setw(10)<<t.id()<<setw(10)<<t.wcet()<<setw(10)<<t.period();
		out<<setw(10)<<t.deadline()<<setw(10)<<t.wcets(0);
		for (int k=1; k<sw.units(); k++)
			out<<", "<<t.wcets(k);
		out<<endl;
	}
	out<<endl;

	return 1;
}

