#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "le ScavTrap a bien ete cree" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)  {
	std::cout << "le ScavTrap " << name << " a bien ete cree" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "le ScavTrap " << this->_name << " a bien ete detruit" << std::endl;

}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	this->_name = rhs._name;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	this->_hitPoints = rhs._hitPoints;
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " le fabuleux ScavTrap n'a plus d'energie, il ne peut plus attaquer !" << std::endl;
		return;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "Malheureusement " << this->_name << " le fabuleux ScavTrap es mort, il ne peut plus attaquer" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << this->_name << " le fabuleux ScavTrap attack " << target << ", " << target << " perd " << this->_attackDamage << "pv" << std::endl;
}

void ScavTrap::guardGate() {
	if (this->_hitPoints <= 0)
	{
		std::cout << "PAR LE POUVOIR DES DIEUX " << this->_name << " PASSE EN MODE rien du tout parce qu'il est mort mdr" << std::endl;
		return;
	}
	std::cout << "PAR LE POUVOIR DES DIEUX " << this->_name << " PASSE EN MODE portier..." << std::endl;
}
