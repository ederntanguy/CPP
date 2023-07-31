#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoints(100), energyPoints(50), attackDamage(20) {
	std::cout << "le ClapTrap a bien ete cree" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "le ClapTrap " << src.name << " a bien ete cree" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(100), energyPoints(50), attackDamage(20) {
	std::cout << "le ClapTrap " << name << " a bien ete cree" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "le ClapTrap " << this->name << " a bien ete detruit" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	this->attackDamage = rhs.attackDamage;
	this->energyPoints = rhs.energyPoints;
	this->hitPoints = rhs.hitPoints;
	this->name = rhs.name;
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (this->energyPoints <= 0)
	{
		std::cout << this->name << " n'a plus d'energie, il ne peut plus attaquer !" << std::endl;
		return;
	}
	else if (this->hitPoints <= 0)
	{
		std::cout << "Malheureusement " << this->name << " est mort, il ne peut plus attaquer" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << this->name << " attack " << target << ", " << target << " perd " << this->attackDamage << "pv" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints <= 0)
	{
		std::cout << "Son adversaire s'acharne vraiment sur lui car il est deja mort..." << std::endl;
		return;
	}
	if (this->hitPoints <= amount)
	{
		this->hitPoints = 0;
		std::cout << "avec cette attaque "  << this->name << " succombe a ses blessures" << std::endl;
		return;
	}
	std::cout << this->name << " perd " << amount << "pv, il ne lui reste plus que " << this->hitPoints - amount << "pv" << std::endl;

	this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints <= 0)
	{
		std::cout << this->name << " n'a plus d'energie, il ne peut plus se soigner !" << std::endl;
		return;
	}
	else if (this->hitPoints <= 0)
	{
		std::cout << "Malheureusement " << this->name << " est mort, on ne peut plus rien faire pour lui" << std::endl;
		return;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << this->name << " gagne " << amount << " pv il a maintenant " << this->hitPoints << "pv" << std::endl;
}
