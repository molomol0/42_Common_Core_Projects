#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:

		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const & src);
		~Fixed();

		Fixed &	operator=(Fixed const & rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

	private:

		int					_value;
		static const int	_bits = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);
int				power(const float, int pow);

#endif