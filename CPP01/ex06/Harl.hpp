#ifndef CPP01_HARL_HPP
#define CPP01_HARL_HPP
#include <iostream>


class Harl {

public:
	Harl();
	~Harl();
	void complain( std::string level );

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void (Harl::*f[4])();

};


#endif //CPP01_HARL_HPP
