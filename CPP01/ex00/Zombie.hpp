#ifndef CPP01_ZOMBIE_HPP
#define CPP01_ZOMBIE_HPP

#include <iostream>

class Zombie {

public:
	Zombie(std::string initName);
	~Zombie();
	void announce( void );
private:
	std::string name;

};


#endif //CPP01_ZOMBIE_HPP
