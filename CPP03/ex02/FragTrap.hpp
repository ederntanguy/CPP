#ifndef CPP03_FRAGTRAP_HPP
#define CPP03_FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	FragTrap();
	FragTrap(const FragTrap &src);
	FragTrap(const std::string &name);
	~FragTrap();

	FragTrap &operator=(const FragTrap &rhs);

	void attack(const std::string& target);
	void highFivesGuys(void);

};


#endif //CPP03_FRAGTRAP_HPP
