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

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
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


std::ostream &operator<<(std::ostream &o, const Fixed &i)
{
	o << (static_cast<float>(i.getRawBits()) / (1 << 8));
	return o;
}







