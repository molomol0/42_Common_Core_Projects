#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name("Default_name"), _hit_points(10), _energy_points(10), _attack_damage(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):_name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "Assignation opeator overload called" << std::endl;

	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;

	return *this;	
}

std::string	ClapTrap::getName(void)
{
	return this->_name;
}

unsigned int	ClapTrap::getHitPoint(void)
{
	return this->_hit_points;
}

unsigned int	ClapTrap::getEnergyPoint(void)
{
	return this->_energy_points;
}

unsigned int	ClapTrap::getAttackDamage(void)
{
	return this->_attack_damage;
}

void	ClapTrap::setName(std::string new_value)
{
	this->_name = new_value;
}

void	ClapTrap::setHitpoint(unsigned int new_value)
{
	this->_hit_points = new_value;
}

void	ClapTrap::setEnergypoint(unsigned int new_value)
{
	this->_energy_points = new_value;
}

void	ClapTrap::setAtackDamage(unsigned int new_value)
{
	this->_attack_damage = new_value;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
	this->_hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " be repaired for " << amount << " points!" << std::endl;
	this->_hit_points += amount;
}
