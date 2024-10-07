#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	//allocation on the heap with new()
	//sur la heap parce qu'on a besoin de retourner le zombie et la stack ce delete quand la methode se finit donc ca marche pas
	Zombie	*zombie = new Zombie(name);

	return (zombie);
}