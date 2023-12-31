#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "le FragTrap a bien ete cree" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "le FragTrap " << name <<  " a bien ete cree" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	std::cout << "le FragTrap " << src.name << " a bien ete cree" << std::endl;
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout << "le FragTrap " << this->name << " a bien ete detruit" << std::endl;
}


void FragTrap::highFivesGuys(void) {
	std::string answer;
	std::cout << "votre tout mignon fragTrap vous demande de faire un High Fives y/n : ";
	std::getline(std::cin, answer);
	if (answer == "y" || answer == "yes" || answer == "Y" || answer == "YES")
		std::cout << this->name << " prend sont elan, saute a votre hauteur et vous claque son meilleur Hive Fives" << std::endl;
	else
		std::cout << this->name << " prend sont elan, saute a votre hauteur et vous lui lacher un gros vent, vous avez fait pleurer " << this->name << "..." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	this->name = rhs.name;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage =rhs.attackDamage;
	this->hitPoints = rhs.hitPoints;
	return *this;
}
