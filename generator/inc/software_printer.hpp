#ifndef __SOFTWARE_SERIALIZER_HPP__
#define __SOFTWARE_SERIALIZER_HPP__

#include <problem.pb.h>

#include <fstream>


/*! \brief print a generated problem (only software module) using protobuf
 *
 * author Mario Bambagini
 */
class SoftwarePrinter
{

public:

	/*! \brief Print the software configuration
	 *
	 * \param filename destination file
	 * \param gen generated problem to print
	 */
	virtual int serialize (std::ostream& out, Problem::Software& sw);

	virtual ~SoftwarePrinter() {}
};

#endif //__SOFTWARE_SERIALIZER_HPP__

