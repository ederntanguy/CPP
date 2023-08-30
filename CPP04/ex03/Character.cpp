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

Character::~Character() {
	for (int i = 0; i < 4; ++i)
	{
		delete inventory[i];
	}
}

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

void Character::unequip(int idx)
{
	if (idx < 4 && inventory[idx] != NULL)
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 4 && inventory[idx] != NULL)
		inventory[idx]->use(target);
}

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
