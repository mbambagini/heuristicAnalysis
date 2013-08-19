#ifndef __SERIALIZER_PROTOBUF_HPP__
#define __SERIALIZER_PROTOBUF_HPP__


#include <serializer.hpp>


/*! \brief protobuf is used to serialize data
 *
 */
class SerializerProtobuf: public Serializer
{
public:

	bool serialize (const std::string& file, bool feas,	int csa, int tsa);
};


#endif //__SERIALIZER_PROTOBUF_HPP__

