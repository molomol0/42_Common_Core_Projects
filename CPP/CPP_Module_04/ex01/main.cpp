#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int main()
{
	//Subject tests
	Animal*	animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 10; i++)
	{
		std::cout << *animals[i] << std::endl;
		animals[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
		delete animals[i];

	//Additional tests on cats
	Cat *cats[5];
	for (int i = 0; i < 5; i++)
		cats[i] = new Cat();
	for (int i = 0; i < 5; i++)
		cats[i]->put_idea("be destruction", 0);
	for (int i = 0; i < 5; i++)
		cats[i]->print_ideas();
	for (int i = 0; i < 5; i++)
		delete cats[i];

	//Additional tests on dogs
	Dog *dogs[5];
	for (int i = 0; i < 5; i++)
		dogs[i] = new Dog();
	for (int i = 0; i < 5; i++)
	{
		dogs[i]->put_idea("be a good boy", 0);
		dogs[i]->put_idea("be human best friend", 1);
		dogs[i]->put_idea("be pretty", 2);
	}
	for (int i = 0; i < 5; i++)
		dogs[i]->print_ideas();
	for (int i = 0; i < 5; i++)
		delete dogs[i];

	//Deep copy tests
	Dog dog1;
	dog1.put_idea("be a good boy", 0);
	std::cout << dog1 << std::endl;
	dog1.makeSound();
	dog1.print_ideas();

	Dog	dog2(dog1);
	std::cout << dog2 << std::endl;
	dog2.makeSound();
	dog2.print_ideas();

	return 0;
}
