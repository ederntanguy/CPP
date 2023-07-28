#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(0.0f, 6.0f);
	Point b(-5.0f, 1.0f);
	Point c(2.0f, -2.0f);
	Point evaluated(0.0f, 5.99f);
	bsp(a, b, c, evaluated);

	evaluated = Point(0.0f, 6.0f);
	bsp(a, b, c, evaluated);

	evaluated = Point(-6.0f, 6.0f);
	bsp(a, b, c, evaluated);

	evaluated = Point(-4.4f, 1.0f);
	bsp(a, b, c, evaluated);

	evaluated = Point(-0.5f, -0.9);
	bsp(a, b, c, evaluated);

	evaluated = Point(1000.0f, 1000.0f);
	bsp(a, b, c, evaluated);


	return 0;
}