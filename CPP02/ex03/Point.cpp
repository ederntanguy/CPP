#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point &src) {
	*this = src;
}

Point::~Point() {}

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;
}

Point &Point::operator=(const Point &rhs) {
	_x = rhs.getX();
	_y = rhs.getY();
	return *this;
}
