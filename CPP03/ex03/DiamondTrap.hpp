#ifndef CPP03_DIAMONDTRAP_HPP
#define CPP03_DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap &src);
	DiamondTrap(const std::string &name);
	~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &rhs);


private:
	std::string name;

};


#endif //CPP03_DIAMONDTRAP_HPP
