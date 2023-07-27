#ifndef CPP02_FIXED_HPP
#define CPP02_FIXED_HPP
#include <iostream>

class Fixed {

public:
	Fixed();
	Fixed(const Fixed &src);
	~Fixed();

	Fixed &operator=(const Fixed &rhs);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int _rawBits;
	static const int scale;

};


#endif //CPP02_FIXED_HPP
