#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(const std::string& initName) : name(initName) {}

Zombie::~Zombie() {
	std::cout << "The Zombie: " << this->name << "was destructed" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}