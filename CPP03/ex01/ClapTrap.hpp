#ifndef CPP03_CLAPTRAP_HPP
#define CPP03_CLAPTRAP_HPP
#include <iostream>

class ClapTrap {

public:
	ClapTrap();
	ClapTrap(const ClapTrap &src);
	ClapTrap(const std::string &name);
	~ClapTrap();

	ClapTrap	&operator=(const ClapTrap &rhs);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

};


#endif //CPP03_CLAPTRAP_HPP
