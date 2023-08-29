#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &src) : AMateria(src)
{
	*this = src;
}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

AMateria *Ice::clone() const
{
	return NULL;
}
