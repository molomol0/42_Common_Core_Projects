#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap();

		ClapTrap &operator=(ClapTrap const &rhs);

		std::string		getName(void);
		unsigned int	getHitPoint(void);
		unsigned int	getEnergyPoint(void);
		unsigned int	getAttackDamage(void);
		void			setName(std::string new_value);
		void			setHitpoint(unsigned int new_value);
		void			setEnergypoint(unsigned int new_value);
		void			setAtackDamage(unsigned int new_value);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:

		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
};

#endif