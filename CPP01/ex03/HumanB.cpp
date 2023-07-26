#include "HumanB.hpp"

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {}

HumanB::HumanB(const std::string &name, Weapon &weapon) : _name(name) {
	this->_weapon = &weapon;
}

HumanB::~HumanB() {}

void HumanB::attack() {
	if (!_weapon) {
		std::cout << this->_name << " can't attack cause he don't have a _weapon" << std::endl;
		return;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
