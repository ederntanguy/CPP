
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
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	AMateria *test = new Cure();
	src->learnMateria(test);
	delete test;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	AMateria* tmp1;
	AMateria* tmp2;
	AMateria* tmp3;
	AMateria* tmp4;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	tmp3 = src->createMateria("cure");
	me->equip(tmp3);
	tmp4 = src->createMateria("cure");
	me->equip(tmp4);
	delete tmp4;
	me->unequip(2);
	me->unequip(2);
	delete tmp2;
	ICharacter* bob = new Character("bob");
	me->use(2, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}