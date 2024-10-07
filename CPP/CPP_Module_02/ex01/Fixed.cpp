#include "Fixed.hpp"

Fixed::Fixed(void):_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value):_value(value * power(2, this->_bits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value):_value(std::roundf(value * power(2, this->_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();

	return (*this);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)power(2, this->_bits));
}

int	Fixed::toInt(void) const 
{
	return ((int)this->_value / (int)power(2, this->_bits));
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}

int		power(const float value, int pow)
{
	if (pow == 0)
		return 1;
	else if (pow < 0)
		return 1 / power(value, -pow);
	else
		return value * power(value, pow - 1);
}