#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "le DiamondTrap a bien ete cree" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), FragTrap(src), ScavTrap(src){
	std::cout << "le DiamondTrap " << src.name << "a bien ete cree" << std::endl;
	*this = src;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), name(name) {
	std::cout << "le DiamondTrap " << name << "a bien ete cree" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "le DiamondTrap " << this->name << "a bien ete detruit" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
	this->name = rhs.name;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << this->name << " " << ClapTrap::name << std::endl;
}

