#include "Character.hpp"

#include <string>

#include "Ice.hpp"
#include "Cure.hpp"

Character::Character() : _name("") {}

Character::Character(std::string &name) : _name(name) {}

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
	(void)m;
}

void Character::unequip(int idx)
{
	(void)idx;
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
