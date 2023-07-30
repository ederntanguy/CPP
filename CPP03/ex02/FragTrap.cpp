#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "le FragTrap a bien ete cree" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "le FragTrap " << name <<  " a bien ete cree" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	std::cout << "le FragTrap " << this->_name <<  " a bien ete cree" << std::endl;
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout << "le FragTrap " << this->_name <<  " a bien ete detruit" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " l'incroyable FragTrap n'a plus d'energie, il ne peut plus attaquer !" << std::endl;
		return;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "Malheureusement " << this->_name << " l'incroyable FragTrap est mort, il ne peut plus attaquer" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << this->_name << " l'incroyable FragTrap attack " << target << ", " << target << " perd " << this->_attackDamage << "pv" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::string answer;
	std::cout << "votre tout mignon fragTrap vous demande de faire un High Fives y/n : ";
	std::getline(std::cin, answer);
	if (answer == "y" || answer == "yes" || answer == "Y" || answer == "YES")
		std::cout << this->_name << " prend sont elan, saute a votre hauteur et vous claque son meilleur Hive Fives" << std::endl;
	else
		std::cout << this->_name << " prend sont elan, saute a votre hauteur et vous lui lacher un gros vent, vous avez fait pleurer " << this->_name << "..." << std::endl;
}
