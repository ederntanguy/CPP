#include "Fixed.hpp"

const int Fixed::_scale = 8;

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &value) : _rawBits(value << _scale) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &value) : _rawBits(roundf(value * (1 << _scale))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return this->_rawBits;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_rawBits) / (1 << _scale);
}

int Fixed::toInt(void) const {
	return this->_rawBits >> _scale;
}

//Fixed &Fixed::operator++(const Fixed &rhs) {
//	return <#initializer#>;
//}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}

Fixed &Fixed::operator*(const Fixed &rhs) {
	this->_rawBits *= rhs.getRawBits();
	return *this;
}

Fixed &Fixed::operator/(const Fixed &rhs) {
	this->_rawBits /= rhs.getRawBits();
	return *this;
}

Fixed &Fixed::operator-(const Fixed &rhs) {
	this->_rawBits -= rhs.getRawBits();
	return *this;}

Fixed &Fixed::operator+(const Fixed &rhs) {
	this->_rawBits += rhs.getRawBits();
	return *this;}

bool Fixed::operator!=(const Fixed &rhs) const {
	if (this->_rawBits != rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &rhs) const {
	if (this->_rawBits != rhs.getRawBits())
		return true;
	return false;}

bool Fixed::operator<=(const Fixed &rhs) const {
	if (this->_rawBits != rhs.getRawBits())
		return true;
	return false;}

bool Fixed::operator>(const Fixed &rhs) const {
	if (this->_rawBits != rhs.getRawBits())
		return true;
	return false;}

bool Fixed::operator<(const Fixed &rhs) const {
	if (this->_rawBits != rhs.getRawBits())
		return true;
	return false;}

bool Fixed::operator==(const Fixed &rhs) const {
	if (this->_rawBits != rhs.getRawBits())
		return true;
	return false;}

//Fixed &Fixed::operator--(const Fixed &rhs) {
//	return <#initializer#>;
//}

const int Fixed::constMin(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return b.getRawBits();
	return  a.getRawBits();
}

int Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return b.getRawBits();
	return  a.getRawBits();
}

const int Fixed::constMan(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return b.getRawBits();
	return  a.getRawBits();}

int Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return b.getRawBits();
	return  a.getRawBits();}


std::ostream &operator<<(std::ostream &o, const Fixed &i)
{
	o << (static_cast<float>(i.getRawBits()) / (1 << 8));
	return o;
}







