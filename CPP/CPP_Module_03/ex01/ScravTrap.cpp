#include "ScravTrap.hpp"

ScravTrap::ScravTrap() : ClapTrap()
{
	std::cout << "ScravTrap default constructor called" << std::endl;
	setHitpoint(100);
	setEnergypoint(50);
	setAtackDamage(20);
}

ScravTrap::ScravTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScravTrap parametric constructor called" << std::endl;
	setHitpoint(100);
	setEnergypoint(50);
	setAtackDamage(20);
}

ScravTrap::ScravTrap(ScravTrap &src)
{
	std::cout << "ScravTrap copy constructor called" << std::endl;
	*this = src;
}

ScravTrap::~ScravTrap()
{
	std::cout << "ScravTrap Destructor called" << std::endl;
}

ScravTrap &ScravTrap::operator=(ScravTrap &rhs)
{
	std::cout << "ScravTrap assignation operator overload called" << std::endl;

	setName(rhs.getName());
	setHitpoint(rhs.getHitPoint());
	setEnergypoint(rhs.getEnergyPoint());
	setAtackDamage(rhs.getAttackDamage());

	return *this;
}

void	ScravTrap::attack(std::string const & target)
{
	std::cout << "ScravTrap " << this->getName() << " attack " << target << " causing " << this->getAttackDamage() << " points of damage !" << std::endl;
}

void	ScravTrap::guardGate(void)
{
	std::cout << "ScravTrap " << this->getName() << " have enterred in Gate keeper mode" << std::endl;
}
