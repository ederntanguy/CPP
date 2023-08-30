#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria(const std::string &type) : _type(type){}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return this->_type;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	this->_type = rhs.getType();
	return *this;
}



