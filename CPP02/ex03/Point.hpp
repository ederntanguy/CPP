#ifndef CPP02_POINT_HPP
#define CPP02_POINT_HPP
#include "Fixed.hpp"

class Point {

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &src);
	~Point();

	Point	&operator=(const Point &rhs);

	Fixed getX() const;
	Fixed getY() const;

private:
	Fixed _x;
	Fixed _y;
};


#endif //CPP02_POINT_HPP
