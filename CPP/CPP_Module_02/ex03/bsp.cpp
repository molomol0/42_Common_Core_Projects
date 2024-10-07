#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	x_min = Fixed::min(a.getX(), b.getX());
	x_min = Fixed::min(x_min, c.getX());

	Fixed	x_max = Fixed::max(a.getX(), b.getX());
	x_max = Fixed::max(x_max, c.getX());


	Fixed	y_min = Fixed::min(a.getY(), b.getY());
	y_min = Fixed::min(y_min, c.getY());

	Fixed	y_max = Fixed::max(a.getY(), b.getY());
	y_max = Fixed::max(y_max, c.getY());

	Fixed determinant_a = (point.getX() - b.getX()) * (c.getY() - b.getY()) - (point.getY() - b.getY()) * (c.getX() - b.getX());
	Fixed determinant_b = (point.getX() - c.getX()) * (a.getY() - c.getY()) - (point.getY() - c.getY()) * (a.getX() - c.getX());
	Fixed determinant_c = (point.getX() - a.getX()) * (b.getY() - a.getY()) - (point.getY() - a.getY()) * (b.getX() - a.getX());

	if ((x_min < point.getX() && x_max > point.getX()) && (y_min < point.getY() && y_max > point.getY()))
	{
		if ((determinant_a * determinant_b > 0) && (determinant_b * determinant_c > 0))
			return true;
	}
	return false;
}
