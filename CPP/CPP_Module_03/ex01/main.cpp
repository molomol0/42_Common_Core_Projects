#include "ClapTrap.hpp"
#include "ScravTrap.hpp"

int main(void)
{
	ScravTrap bob("Bob");
	ScravTrap patrick("Patrick");

	std::cout << std::endl;
	std::cout << "Les stats de bob sont : " << std::endl << "Hit points : " << bob.getHitPoint() << std::endl << "Energy points : " << bob.getEnergyPoint() << std::endl << "Attack damage : " << bob.getAttackDamage() << std::endl << std::endl;
	std::cout << "Les stats de patrick sont : " << std::endl << "Hit points : " << patrick.getHitPoint() << std::endl << "Energy points : " << patrick.getEnergyPoint() << std::endl << "Attack damage : " << patrick.getAttackDamage() << std::endl << std::endl;
	bob.attack(patrick.getName());
	patrick.takeDamage(bob.getAttackDamage());
	std::cout << "Les stats de patrick sont : " << std::endl << "Hit points : " << patrick.getHitPoint() << std::endl << "Energy points : " << patrick.getEnergyPoint() << std::endl << "Attack damage : " << patrick.getAttackDamage() << std::endl << std::endl;
	patrick.beRepaired(bob.getAttackDamage());
	std::cout << "Les stats de bob sont : " << std::endl << "Hit points : " << bob.getHitPoint() << std::endl << "Energy points : " << bob.getEnergyPoint() << std::endl << "Attack damage : " << bob.getAttackDamage() << std::endl << std::endl;
	std::cout << "Les stats de patrick sont : " << std::endl << "Hit points : " << patrick.getHitPoint() << std::endl << "Energy points : " << patrick.getEnergyPoint() << std::endl << "Attack damage : " << patrick.getAttackDamage() << std::endl << std::endl;

	bob.guardGate();
	patrick.guardGate();
	std::cout << std::endl;
}