
#include <iostream>
#include <string>

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	if (tmp)
		std::cout << tmp->getType() << std::endl;
	me->equip(tmp);
	me->unequip(0);
	tmp = src->createMateria("cure");
	std::cout << tmp->getType() << std::endl;
	tmp = src->createMateria("ice");
	if (tmp)
		std::cout << tmp->getType() << std::endl;
//	me->equip(tmp);
//	ICharacter* bob = new Character("bob");
//	me->use(0, *bob);
//	me->use(1, *bob);
//	delete bob;
//	delete me;
//	delete src;
	return 0;
}