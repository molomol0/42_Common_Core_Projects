/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:48:07 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/15 15:33:47 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	src->printMateria();
	
	ICharacter* me = new Character("me");

	AMateria* tmp[6];
	tmp[0] = src->createMateria("ice");
	tmp[1] = src->createMateria("cure");
	tmp[2] = src->createMateria("fire");
	tmp[3] = src->createMateria("ice");
	tmp[4] = src->createMateria("cure");
	tmp[5] = src->createMateria("ice");

	for (int i = 0; i < 6; i++)
		me->equip(tmp[i]);
	
	me->printChara();

	me->unequip(1);
	me->unequip(1);
	me->unequip(4);
	me->printChara();

	AMateria* tmp2 = src->createMateria("ice");
	me->equip(tmp2);

	me->printChara();

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(5, *bob);
	
	delete tmp[1]; //pour les equipement unequip
	delete bob;
	delete me;
	delete src;

	return 0;
}

// int	main(void)
// {
// 	std::cout << "\033[1;31m------------------------------\033[0m" << std::endl;
// 	std::cout << "\033[1;31m|           TESTS            |\033[0m" << std::endl;
// 	std::cout << "\033[1;31m------------------------------\033[0m" << std::endl;

// 	std::cout << std::endl <<"\033[1;32mconstructors:\033[0m" << std::endl;
	
// 	IMateriaSource* book_a = new MateriaSource();
// 	IMateriaSource* book_b = new MateriaSource();
// 	ICharacter*		pablo = new Character("pablo");
// 	ICharacter*		louis = new Character("louis");

// 	std::cout <<"\033[1;32mbasic tests:\033[0m" << std::endl;
// 	book_a->learnMateria(new Ice());
// 	book_a->learnMateria(new Cure());
// 	pablo->equip(book_a->createMateria("ice"));
// 	pablo->equip(book_a->createMateria("cure"));
// 	std::cout << "Name is: " << pablo->getName() << std::endl;
// 	pablo->use(0, *louis);
// 	pablo->use(1, *louis);
// 	std::cout <<"\033[1;32mMateriaSource tests:\033[0m" << std::endl;
// 	AMateria* test = new Ice();
// 	AMateria* test2 = new Cure();
// 	book_a->learnMateria(test);
// 	book_a->learnMateria(new Cure());
// 	book_a->learnMateria(test);
// 	book_a->learnMateria(NULL);
// 	book_a->learnMateria(test2);
// 	test = book_a->createMateria("ice");
// 	delete test;
// 	test = book_a->createMateria("cure");
// 	delete test;
// 	book_a->createMateria("");
// 	book_a->createMateria("plouf");
// 	book_b->learnMateria(NULL);
// 	book_b->createMateria("ice");
// 	MateriaSource	a;
// 	MateriaSource	b;
// 	a.learnMateria(new Ice());
// 	b = a;
// 	delete a.createMateria("ice");
// 	delete b.createMateria("ice");
// 	test = NULL;
// 	std::cout << "here: " << test << std::endl;
// 	for (int i = 0; i < 4; i++)
// 		a.learnMateria(test);
// 	a.printMateria();
// 	b.printMateria();
// 	AMateria *test_c;
// 	test_c = a.createMateria("cure");
// 	std::cout << test_c << std::endl;
// 	std::cout << std::endl <<"\033[1;32mCharacter tests:\033[0m" << std::endl;
// 	ICharacter* souarez = new Character("suarez");
// 	souarez->equip(a.createMateria("ice"));
// 	souarez->equip(a.createMateria("ice"));
// 	souarez->equip(NULL);
// 	souarez->equip(a.createMateria("cure"));
// 	souarez->equip(a.createMateria("ds"));
// 	ICharacter* lopez = new Character("lopez");
// 	AMateria *floor[4];
// 	floor[0] = a.createMateria("ice");
// 	floor[1] = a.createMateria("ice");
// 	floor[2] = a.createMateria("ice");
// 	floor[3] = a.createMateria("fsfdf");
// 	for (int i = 0; i < 4; i++)
// 		lopez->equip(floor[i]);
// 	for (int i = 0; i < 4; i++)
// 		lopez->unequip(i);
// 	lopez->unequip(0);
// 	Character bartez("bartez");
// 	for (int i = 0; i < 4; i++)
// 		bartez.equip(floor[i]);
// 	bartez.printChara();
// 	for (int i = 0; i < 4; i++)
// 		bartez.unequip(i);
// 	bartez.printChara();
// 	for (int i = 0; i < 4; i++)
// 		bartez.equip(floor[i]);
// 	bartez.unequip(1);
// 	bartez.printChara();
// 	bartez.unequip(5);
// 	for (int i = 0; i < 4; i++)
// 		bartez.unequip(i);
// 	bartez.printChara();
// 	AMateria *stock[3];
// 	stock[0] = book_a->createMateria("cure");
// 	stock[1] = book_a->createMateria("ice");
// 	stock[2] = book_a->createMateria("ice");
// 	for (int i = 0; i < 3; i++)
// 		bartez.equip(stock[i]);
// 	bartez.unequip(1);
// 	bartez.printChara();
// 	Character *cortez =  new Character(bartez);
// 	cortez->printChara();
	
	
	
// 	std::cout << std::endl <<"\033[1;32mdestructors:\033[0m" << std::endl;
// 	delete book_a;
// 	delete book_b;
// 	delete pablo;
// 	delete louis;
// 	delete test2;
// 	delete souarez;
// 	delete lopez;
// 	delete cortez;
// 	for (int i = 0; i < 3; i++)
// 		delete floor[i];
// 	delete stock[1];
// }
