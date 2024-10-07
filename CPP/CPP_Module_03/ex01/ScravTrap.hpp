#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScravTrap : public ClapTrap
{
	public:

		ScravTrap();
		ScravTrap(std::string name);
		ScravTrap(ScravTrap &src);
		~ScravTrap();

		ScravTrap &operator=(ScravTrap &rhs);

		void attack(std::string const & target);
		void guardGate(void);
};

#endif