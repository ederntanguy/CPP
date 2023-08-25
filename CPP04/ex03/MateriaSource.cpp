#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *)
{
	static int count = 0;
	if (count >= 4)
		return;
	*materiaType[0] = AMateria;
	count++;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	return nullptr;
}
