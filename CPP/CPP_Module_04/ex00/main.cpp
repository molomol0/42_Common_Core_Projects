#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* plati = new WrongAnimal();
	const WrongAnimal* garf = new WrongCat();
	std::cout << std::endl;
	std::cout << *meta << std::endl;
	std::cout << *j << std::endl;
	std::cout << *i << std::endl;
	std::cout << *plati << std::endl;
	std::cout << *garf << std::endl;
	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	garf->makeSound();
	plati->makeSound();
	std::cout << std::endl;
	delete(meta);
	delete(j);
	delete(i);
	delete(plati);
	delete(garf);
	return 0;
}