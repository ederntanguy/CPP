#include "MateriaSource.hpp"

#include "AMateria.hpp"

MateriaSource::MateriaSource() {
	materiaType[0] = NULL;
	materiaType[1] = NULL;
	materiaType[2] = NULL;
	materiaType[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource::~MateriaSource() {}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	int i = 0;
	while (i < 4)
	{
		this->materiaType[i] = rhs.materiaType[i];
		i++;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *type)
{
	static int count = 0;
	while (materiaType[count] != NULL)
		count++;
	if (count >= 4)
		return;
	materiaType[count] = type;
}
#include <iostream>
AMateria *MateriaSource::createMateria(const std::string &type)
{
	int i = 0;
	while (materiaType[i] != NULL)
	{
		if (materiaType[i]->getType() == type)
		{
			materiaType[i]->clone();
			return materiaType[i]->clone();
		}
		i++;
	}
	return NULL;
}