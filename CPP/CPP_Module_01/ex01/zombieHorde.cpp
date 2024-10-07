#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	zombies = new Zombie[N];
	int index = 0;

	while (index < N)
	{
		zombies[index].Zombie::setName(name);
		index++;
	}
	return (zombies);
}