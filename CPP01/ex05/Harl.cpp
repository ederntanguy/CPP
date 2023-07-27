#include "Harl.hpp"

Harl::Harl() {
	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
}

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
	std::cout << "je me suis fait manger le bras" << std::endl;
}

void Harl::complain(std::string level) {
	if (level == "DEBUG")
		(this->*f[0])();
	else if (level == "INFO")
		(this->*f[1])();
	else if (level == "WARNING")
		(this->*f[2])();
	else if (level == "ERROR")
		(this->*f[3])();
}