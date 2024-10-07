#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	public:

		Point();
		Point(float const float_x, float const float_y);
		Point(Point const & src);
		~Point();

		Point &	operator=(Point const & rhs);

		Fixed	getX() const;
		Fixed	getY() const;
		

	private:

		Fixed const	_x;
		Fixed const	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif