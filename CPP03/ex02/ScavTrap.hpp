#ifndef CPP03_SCAVTRAP_HPP
#define CPP03_SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &src);
	~ScavTrap();

	ScavTrap	&operator=(const ScavTrap &rhs);

	void attack(const std::string& target);
	void guardGate();
};


#endif //CPP03_SCAVTRAP_HPP
