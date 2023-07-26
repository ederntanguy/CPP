#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "Ho ba tien voila quelqu'un petit ours brun" << std::endl;
}

void Harl::info() {
	std::cout << "Il semblerait qu'il y est un ours brun a la maison" << std::endl;
}

void Harl::warning() {
	std::cout << "Mais WTF c'est pas normal qu'il y est un ours brun a la maison" << std::endl;
}

void Harl::error() {
	std::cout << "AU SECROUS IL Y A UN OURS BRUN A LA MAISON" << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*f[4])();

	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
	(this->*f[level[0] - '0'])();
}