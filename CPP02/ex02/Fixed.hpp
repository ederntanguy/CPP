#ifndef CPP02_FIXED_HPP
#define CPP02_FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {

public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed(const int &value);
	Fixed(const float &value);
	~Fixed();

	Fixed	&operator=(const Fixed &rhs);
	bool	operator==(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator>(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;
	Fixed	&operator+(const Fixed &rhs);
	Fixed	&operator-(const Fixed &rhs);
	Fixed	&operator/(const Fixed &rhs);
	Fixed	&operator*(const Fixed &rhs);
//	Fixed	&operator++(const Fixed &rhs);
//	Fixed	&operator--(const Fixed &rhs);
	static int			min(const Fixed &a, const Fixed &b);
	static const int	constMin(const Fixed &a, const Fixed &b);
	static int			max(const Fixed &a, const Fixed &b);
	static const int	constMan(const Fixed &a, const Fixed &b);



	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int _rawBits;
	static const int _scale;

};

std::ostream &operator<<(std::ostream &o, const Fixed &i);

#endif //CPP02_FIXED_HPP
