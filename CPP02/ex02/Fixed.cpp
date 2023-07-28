#include "Fixed.hpp"

const int Fixed::_scale = 8;

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const int &value) : _rawBits(value << _scale) {}

Fixed::Fixed(const float &value) : _rawBits(roundf(value * (1 << _scale))) {
//	std::cout << "ici : " << (1 << _scale) << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return this->_rawBits;
}

void Fixed::setRawBits(const int raw) {
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_rawBits) / (1 << _scale);
}

int Fixed::toInt(void) const {
	return this->_rawBits >> _scale;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	this->_rawBits = rhs.getRawBits();
	return *this;
}

Fixed &Fixed::operator*(const Fixed &rhs) {
	this->setRawBits(static_cast<int>((this->getFixedNumber() * rhs.getFixedNumber()) * (1 << _scale)));
	return *this;
}

Fixed &Fixed::operator/(const Fixed &rhs) {
	this->setRawBits(static_cast<int>((this->getFixedNumber() / rhs.getFixedNumber()) * (1 << _scale)));
	return *this;
}

Fixed &Fixed::operator-(const Fixed &rhs) {
	this->setRawBits(static_cast<int>((this->getFixedNumber() - rhs.getFixedNumber()) * (1 << _scale)));
	return *this;}

Fixed &Fixed::operator+(const Fixed &rhs) {
	this->setRawBits(static_cast<int>((this->getFixedNumber() + rhs.getFixedNumber()) * (1 << _scale)));
	return *this;}

bool Fixed::operator!=(const Fixed &rhs) const {
	if (this->_rawBits != rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &rhs) const {
	if (this->_rawBits >= rhs.getRawBits())
		return true;
	return false;}

bool Fixed::operator<=(const Fixed &rhs) const {
	if (this->_rawBits <= rhs.getRawBits())
		return true;
	return false;}

bool Fixed::operator>(const Fixed &rhs) const {
	if (this->_rawBits > rhs.getRawBits())
		return true;
	return false;}

bool Fixed::operator<(const Fixed &rhs) const {
	if (this->_rawBits < rhs.getRawBits())
		return true;
	return false;}

bool Fixed::operator==(const Fixed &rhs) const {
	if (this->_rawBits == rhs.getRawBits())
		return true;
	return false;}

float Fixed::constMin(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return b.getFixedNumber();
	return  a.getFixedNumber();
}

float Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return b.getFixedNumber();
	return  a.getFixedNumber();
}

float Fixed::constMax(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return b.getFixedNumber();
	return  a.getFixedNumber();}

float Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return b.getFixedNumber();
	return  a.getFixedNumber();}

Fixed &Fixed::operator++(int) {
	Fixed &oldValue = *this;
	Fixed::operator++();
	return oldValue;
}

Fixed &Fixed::operator--(int) {
	Fixed &oldValue = *this;
	Fixed::operator--();
	return oldValue;}

Fixed &Fixed::operator++() {
	this->_rawBits += 1;
	return *this;
}

Fixed &Fixed::operator--() {
	this->_rawBits -= 1;
	return *this;}

float Fixed::getFixedNumber() const {
	return (static_cast<float>(this->getRawBits()) / (1 << 8));
}

std::ostream &operator<<(std::ostream &o, const Fixed &i)
{
	o << (static_cast<float>(i.getRawBits()) / (1 << 8));
	return o;
}







