#include "Zombie.hpp"

int main(void)
{
	int			zombies_number = 100;
	std::string	zombies_name = "bob";
	Zombie* 	zombies = zombieHorde(zombies_number, zombies_name);

	for (int i = 0; i < zombies_number; i++)
		zombies[i].announce();
	
	delete[] zombies;
	return (0);
}