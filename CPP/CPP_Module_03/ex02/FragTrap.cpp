#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	setHitpoint(100);
	setEnergypoint(100);
	setAtackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap parametric constructor called" << std::endl;
	setHitpoint(100);
	setEnergypoint(100);
	setAtackDamage(30);
}

FragTrap::FragTrap(FragTrap &src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &rhs)
{
	std::cout << "FragTrap assignation operator overload called" << std::endl;

	setName(rhs.getName());
	setHitpoint(rhs.getHitPoint());
	setEnergypoint(rhs.getEnergyPoint());
	setAtackDamage(rhs.getAttackDamage());

	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " High Five !" << std::endl;
}
