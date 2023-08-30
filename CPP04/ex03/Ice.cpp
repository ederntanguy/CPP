#include "Ice.hpp"

#include <iostream>


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
	return new Ice();
}

void Ice::use(ICharacter &target) {
	std::cout << "Ice : \"* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}
