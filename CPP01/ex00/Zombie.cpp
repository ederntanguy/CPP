#include "Zombie.hpp"

Zombie::Zombie(std::string initName) : name(initName) {
	return;
}

Zombie::~Zombie() {
	std::cout << "The Zombie: " << this->name << " was destructed" << std::endl;
	return;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}