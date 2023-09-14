#ifndef CPP06_SERIALIZER_HPP
#define CPP06_SERIALIZER_HPP

#include <stdint.h>

#include "struct.hpp"

class Serializer{
public:
	Serializer();
	Serializer(const Serializer &src);
	~Serializer();

	Serializer &operator=(const Serializer &rhs);

	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};

#endif //CPP06_SERIALIZER_HPP
