#include "Weapon.hpp"

Weapon::Weapon(std::string initType) : type(initType) {
	return;
}

Weapon::~Weapon() {
	return;
}

std::string Weapon::getType() {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}