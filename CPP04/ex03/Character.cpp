#include "Character.hpp"

#include <string>

#include "Ice.hpp"
#include "Cure.hpp"

Character::Character() : _name("") {
	inventory[0] = NULL;
	inventory[1] = NULL;
	inventory[2] = NULL;
	inventory[3] = NULL;
}

Character::Character(const std::string &name) : _name(name) {
	inventory[0] = NULL;
	inventory[1] = NULL;
	inventory[2] = NULL;
	inventory[3] = NULL;
}

Character::Character(const Character &src)
{
	*this = src;
}

Character::~Character() {}

const std::string &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	int i = 0;
	while (inventory[i] != NULL)
		i++;
	if (i >= 4)
		return;
	inventory[i] = m;
}

#include <iostream>

void Character::unequip(int idx)
{
	if (idx < 4 && inventory[idx] != NULL)
	{
		std::cout << "ici" << std::endl;
		delete inventory[idx];
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	(void)idx;
	(void)target;
}

//AMateria Character::clone()
//{
//	return ;
//}

Character &Character::operator=(const Character rhs)
{
	int i = 0;
	while (i < 4)
	{
		this->inventory[i] = rhs.inventory[i];
		i++;
	}
	this->_name = rhs.getName();
	return *this;
}
