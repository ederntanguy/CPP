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
	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	&operator++(int);
	Fixed	&operator--(int);
	Fixed	&operator++();
	Fixed	&operator--();
	static Fixed	min(const Fixed &a, const Fixed &b);
	static const Fixed	constMin(const Fixed &a, const Fixed &b);
	static Fixed	max(const Fixed &a, const Fixed &b);
	static const Fixed	constMax(const Fixed &a, const Fixed &b);



	float getFixedNumber() const;
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
