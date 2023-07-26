#ifndef CPP01_WEAPON_HPP
#define CPP01_WEAPON_HPP
#include <iostream>

class Weapon {

public:
	Weapon(std::string initType);
	~Weapon();
	std::string getType();
	void		setType(std::string type);

private:
	std::string type;

};


#endif //CPP01_WEAPON_H
