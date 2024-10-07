#include "Zombie.hpp"

void	randomChump(std::string name)
{
	//allocation on the stack with direct implementation
	//void donc rien a retourner et la raison pour laquelle on creer le zombie est utilise dans la methode donc on utlise la stack
	Zombie	zombie(name);
	zombie.announce();
}