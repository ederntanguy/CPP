#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point ab(b.getX().getFixedNumber() - a.getX().getFixedNumber(), b.getY().getFixedNumber() - a.getY().getFixedNumber());
	Point bc(c.getX().getFixedNumber() - b.getX().getFixedNumber(), c.getY().getFixedNumber() - b.getY().getFixedNumber());
	Point ca(a.getX().getFixedNumber() - c.getX().getFixedNumber(), a.getY().getFixedNumber() - c.getY().getFixedNumber());
	Point ba(a.getX().getFixedNumber() - b.getX().getFixedNumber(), a.getY().getFixedNumber() - b.getY().getFixedNumber());
	Point cb(b.getX().getFixedNumber() - c.getX().getFixedNumber(), b.getY().getFixedNumber() - c.getY().getFixedNumber());
	Point ac(c.getX().getFixedNumber() - a.getX().getFixedNumber(), c.getY().getFixedNumber() - a.getY().getFixedNumber());
	Point ap(point.getX().getFixedNumber() - a.getX().getFixedNumber(), point.getY().getFixedNumber() - a.getY().getFixedNumber());
	Point bp(point.getX().getFixedNumber() - b.getX().getFixedNumber(), point.getY().getFixedNumber() - b.getY().getFixedNumber());
	Point cp(point.getX().getFixedNumber() - c.getX().getFixedNumber(), point.getY().getFixedNumber() - c.getY().getFixedNumber());
//	std::cout << (ab.getX() * ap.getY() - ab.getY() * ap.getX()) * (ab.getX() * ac.getY() - ab.getY() * ac.getX()) << std::endl;
//	std::cout << (bc.getX() * bp.getY() - bc.getY() * bp.getX()) * (bc.getX() * ba.getY() - bc.getY() * ba.getX()) << std::endl;
//	std::cout << (ca.getX() * cp.getY() - ca.getY() * cp.getX()) * (ca.getX() * cb.getY() - ca.getY() * cb.getX()) << std::endl;
	if ((ab.getX() * ap.getY() - ab.getY() * ap.getX()) * (ab.getX() * ac.getY() - ab.getY() * ac.getX()) > 0.0f
			&& (bc.getX() * bp.getY() - bc.getY() * bp.getX()) * (bc.getX() * ba.getY() - bc.getY() * ba.getX()) > 0.0f
			&& (ca.getX() * cp.getY() - ca.getY() * cp.getX()) * (ca.getX() * cb.getY() - ca.getY() * cb.getX()) > 0.0f)
	{
		std::cout << "le point : (" << point.getX() << "," << point.getY() << ") est dans le tirangle abc" << std::endl;
		return true;
	}
	std::cout << "le point : (" << point.getX() << "," << point.getY() << ") n'est pas dans le tirangle abc" << std::endl;
	return false;
}