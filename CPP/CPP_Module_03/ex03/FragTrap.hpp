#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &src);
		~FragTrap();

		FragTrap &operator=(FragTrap &rhs);

		void highFivesGuys(void);
};

#endif