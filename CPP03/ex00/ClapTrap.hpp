#ifndef CPP03_CLAPTRAP_HPP
#define CPP03_CLAPTRAP_HPP
#include <iostream>

class ClapTrap {

public:
	ClapTrap();
	ClapTrap(const ClapTrap &src);
	ClapTrap(std::string name);
	~ClapTrap();

	ClapTrap	&operator=(const ClapTrap &rhs);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

};


#endif //CPP03_CLAPTRAP_HPP
