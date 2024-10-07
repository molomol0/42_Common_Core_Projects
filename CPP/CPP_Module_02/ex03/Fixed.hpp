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

		int		getValue(void) const;
		void	setValue(int new_value);

		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(Fixed const &rhs);
		bool	operator<(Fixed const &rhs);
		bool	operator>=(Fixed const &rhs);
		bool	operator<=(Fixed const &rhs);
		bool	operator==(Fixed const &rhs);
		bool	operator!=(Fixed const &rhs);

		Fixed	operator+(Fixed const &rhs);
		Fixed	operator-(Fixed const &rhs);
		Fixed	operator*(Fixed const &rhs);
		Fixed	operator/(Fixed const &rhs);

		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		static Fixed & min(Fixed &lhs, Fixed &rhs);
		static Fixed const & min(Fixed const & lhs, Fixed const & rhs);
		static Fixed & max(Fixed &lhs, Fixed &rhs);
		static Fixed const & max(Fixed const &lhs, Fixed const &rhs);

	private:

		int					_value;
		static const int	_bits = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);
int				power(const float, int pow);

#endif