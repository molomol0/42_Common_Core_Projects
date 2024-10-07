#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap("Default_clap_name")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScravTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap parametric constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &src)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &rhs)
{
	std::cout << "DiamondTrap assignation operator overload called" << std::endl;

	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;

	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScravTrap::attack(target);
}