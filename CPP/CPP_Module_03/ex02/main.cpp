#include "ClapTrap.hpp"
#include "ScravTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap bob("Bob");
	FragTrap patrick("Patrick");


	std::cout << std::endl;
	std::cout << "Les stats de bob sont : " << std::endl << "Hit points : " << bob.getHitPoint() << std::endl << "Energy points : " << bob.getEnergyPoint() << std::endl << "Attack damage : " << bob.getAttackDamage() << std::endl << std::endl;
	std::cout << "Les stats de patrick sont : " << std::endl << "Hit points : " << patrick.getHitPoint() << std::endl << "Energy points : " << patrick.getEnergyPoint() << std::endl << "Attack damage : " << patrick.getAttackDamage() << std::endl << std::endl;
	bob.attack(patrick.getName());
	patrick.takeDamage(bob.getAttackDamage());
	std::cout << "Les stats de patrick sont : " << std::endl << "Hit points : " << patrick.getHitPoint() << std::endl << "Energy points : " << patrick.getEnergyPoint() << std::endl << "Attack damage : " << patrick.getAttackDamage() << std::endl << std::endl;
	patrick.beRepaired(bob.getAttackDamage());
	std::cout << "Les stats de bob sont : " << std::endl << "Hit points : " << bob.getHitPoint() << std::endl << "Energy points : " << bob.getEnergyPoint() << std::endl << "Attack damage : " << bob.getAttackDamage() << std::endl << std::endl;
	std::cout << "Les stats de patrick sont : " << std::endl << "Hit points : " << patrick.getHitPoint() << std::endl << "Energy points : " << patrick.getEnergyPoint() << std::endl << "Attack damage : " << patrick.getAttackDamage() << std::endl << std::endl;

	bob.highFivesGuys();
	patrick.highFivesGuys();
	std::cout << std::endl;
}