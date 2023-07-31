#ifndef CPP03_FRAGTRAP_HPP
#define CPP03_FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(const FragTrap &src);
	FragTrap(const std::string &name);
	~FragTrap();

	FragTrap &operator=(const FragTrap &rhs);

	void highFivesGuys(void);
//	virtual void attack(const std::string& target);

};


#endif //CPP03_FRAGTRAP_HPP
