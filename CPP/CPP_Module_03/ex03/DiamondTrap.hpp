#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScravTrap.hpp"

class DiamondTrap : public ScravTrap, public FragTrap
{
	public:

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap &src);
		~DiamondTrap();

		DiamondTrap &operator=(DiamondTrap &rhs);

		void attack(std::string const & target);
		void whoAmI(void);

	private:

		std::string _name;
};

#endif