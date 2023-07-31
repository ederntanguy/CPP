#ifndef CPP03_DIAMONDTRAP_HPP
#define CPP03_DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap &src);
	DiamondTrap(const std::string &name);
	~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &rhs);
	void whoAmI();
	using ScavTrap::attack;
protected:
	using FragTrap::hitPoints;
	using ScavTrap::energyPoints;
	using FragTrap::attackDamage;
private:
	std::string name;
};


#endif //CPP03_DIAMONDTRAP_HPP
