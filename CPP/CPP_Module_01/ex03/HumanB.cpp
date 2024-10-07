#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name):_name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB(void)
{
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->_weapon = &new_weapon;
}

void	HumanB::attack(void)
{
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << (*(this->_weapon)).getType() << std::endl;
	else 
		std::cout << this->_name << " is unarmed" << std::endl;
}
