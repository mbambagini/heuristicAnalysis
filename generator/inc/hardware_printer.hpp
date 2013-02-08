#ifndef __SERIALIZER_HARDWARE_HPP__
#define __SERIALIZER_HARDWARE_HPP__

#include <iostream>


#include <problem.pb.h>


/*! \brief Print the actual hardware configuration on the given output stream
 *
 */
class HardwarePrinter
{

public:

	/*! \brief Print the hardware configuration
	 *
	 * \param filename destination file
	 * \param gen generated problem to print
	 */
	virtual int serialize (std::ostream &res, const Problem::Hardware& hw);


	virtual ~HardwarePrinter() {}
};

#endif //__SERIALIZER_HARDWARE_HPP

