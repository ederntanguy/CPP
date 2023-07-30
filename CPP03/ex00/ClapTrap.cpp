#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "le ClapTrap a bien ete cree" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "le ClapTrap " << src._name << " a bien ete cree" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "le ClapTrap " << name << " a bien ete cree" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "le ClapTrap " << this->_name << " a bien ete detruit" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	this->_attackDamage = rhs._attackDamage;
	this->_energyPoints = rhs._energyPoints;
	this->_hitPoints = rhs._hitPoints;
	this->_name = rhs._name;
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " n'a plus d'energie, il ne peut plus attaquer !" << std::endl;
		return;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "Malheureusement " << this->_name << " est mort, il ne peut plus attquer" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << this->_name << " attack " << target << ", " << target << " perd " << this->_attackDamage << "pv" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0)
	{
		std::cout << "Son adversaire s'acharne vraiment sur lui car il est deja mort..." << std::endl;
		return;
	}
	if (this->_hitPoints <= amount)
	{
		this->_hitPoints = 0;
		std::cout << "avec cette attaque "  << this->_name << " succombe a ses blessures" << std::endl;
		return;
	}
	std::cout << this->_name << " perd " << amount << "pv, il ne lui reste plus que " << this->_hitPoints - amount << "pv" << std::endl;

	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " n'a plus d'energie, il ne peut plus attaquer !" << std::endl;
		return;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "Malheureusement " << this->_name << " est mort, on ne peut plus rien faire pour lui" << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << this->_name << " gagne " << amount << " pv il a maintenant " << this->_hitPoints << "pv" << std::endl;
}
