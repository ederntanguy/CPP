#ifndef CPP01_HUMANB_HPP
#define CPP01_HUMANB_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB {

public:
	HumanB(const std::string &name);
	HumanB(const std::string &name, Weapon &weapon);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack();

private:
	std::string	_name;
	Weapon		*_weapon;
};


#endif //CPP01_HUMANB_HPP
