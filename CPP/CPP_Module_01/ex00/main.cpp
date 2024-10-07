#include "Zombie.hpp"

int main(void)
{
	//heap allocation
	Zombie* claude = newZombie("claude");
	(*claude).announce();
	//need to be deleted after utilization
	delete claude;

	//stack allocation
	randomChump("bob");
	//automatically delete the allocated memory at the end of the method()

	return (0);
}