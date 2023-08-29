#include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {}

Cure::Cure(const Cure &src) : AMateria(src)
{
	*this = src;
}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

AMateria *Cure::clone() const
{
	return NULL;
}
