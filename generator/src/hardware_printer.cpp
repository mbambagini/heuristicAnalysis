#include <iomanip>

#include <hardware_printer.hpp>


using namespace std;
using namespace Problem;


int HardwarePrinter::serialize (ostream &res, const Hardware& hw)
{
	res<<"Processors ("<<hw.processors_size()<<", ";
	res<<hw.types_size()<<"):"<<endl;
	res<<"\t"<<setw(5)<<"ID"<<setw(10)<<"TYPE"<<setw(10)<<"Pactive";
	res<<setw(10)<<"Pidle"<<setw(10)<<"Psleep"<<setw(10)<<"Pswitch";
	res<<setw(10)<<"BET"<<setw(10)<<"SPEED"<<endl;
	for (int i=0; i<hw.processors_size(); i++) {
		ProcessorType type = hw.types(hw.processors(i));
		res<<"\t"<<setw(5)<<i<<setw(10)<<type.id();
		res<<setw(10)<<type.pactive();
		res<<setw(10)<<type.pidle()<<setw(10)<<type.psleep();
		res<<setw(10)<<type.pswitching()<<setw(10)<<type.bet();
		res<<setw(10)<<type.speed(0);
		for (int j=1; j<type.speed_size(); j++)
			res<<", "<<type.speed(j);
		res<<endl;
	}
	res<<endl;

	return 1;
}

