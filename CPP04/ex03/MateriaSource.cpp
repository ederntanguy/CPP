#include "MateriaSource.hpp"

#include "AMateria.hpp"

MateriaSource::MateriaSource() {}

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
	(void)type;
	static int count = 0;
	if (count >= 4)
		return;
//	*materiaType[0] = AMateria;
	count++;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	(void)type;
	return NULL;
}