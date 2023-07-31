#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "le ScavTrap a bien ete cree" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)  {
	std::cout << "le ScavTrap " << name << " a bien ete cree" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
	std::cout << "le ScavTrap " << this->name << " a bien ete cree" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "le ScavTrap " << this->name << " a bien ete detruit" << std::endl;

}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	this->name = rhs.name;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	this->hitPoints = rhs.hitPoints;
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (this->energyPoints <= 0)
	{
		std::cout << this->name << " le fabuleux ScavTrap n'a plus d'energie, il ne peut plus attaquer !" << std::endl;
		return;
	}
	else if (this->hitPoints <= 0)
	{
		std::cout << "Malheureusement " << this->name << " le fabuleux ScavTrap est mort, il ne peut plus attaquer" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << this->name << " le fabuleux ScavTrap attack " << target << ", " << target << " perd " << this->attackDamage << "pv" << std::endl;
}

void ScavTrap::guardGate() {
	if (this->hitPoints <= 0)
	{
		std::cout << "PAR LE POUVOIR DES DIEUX " << this->name << " PASSE EN MODE rien du tout parce qu'il est mort mdr" << std::endl;
		return;
	}
	std::cout << "PAR LE POUVOIR DES DIEUX " << this->name << " PASSE EN MODE portier..." << std::endl;
}
