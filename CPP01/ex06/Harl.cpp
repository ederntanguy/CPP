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
	int i = 0;
	if (level == "DEBUG")
		i = 0;
	else if (level == "INFO")
		i = 1;
	else if (level == "WARNING")
		i = 2;
	else if (level == "ERROR")
		i = 3;
	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*f[0])();
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			(this->*f[1])();
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*f[2])();
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*f[3])();
	}
}