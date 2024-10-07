#include "Point.hpp"

Point::Point(void):_x(0), _y(0)
{
}

Point::Point(float const float_x, float const float_y):_x(float_x), _y(float_y)
{
}

Point::Point(Point const & src)
{
	*this = src;
}

Point::~Point(void)
{
}

Point	&Point::operator=(Point const & rhs)
{
	(Fixed)this->_x = rhs.getX();
	(Fixed)this->_y = rhs.getY();

	return (*this);
}

Fixed Point::getX(void) const
{
	return this->_x;
}

Fixed Point::getY(void) const
{
	return this->_y;
}

