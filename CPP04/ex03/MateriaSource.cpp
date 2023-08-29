#include "MateriaSource.hpp"

#include "AMateria.hpp"

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
