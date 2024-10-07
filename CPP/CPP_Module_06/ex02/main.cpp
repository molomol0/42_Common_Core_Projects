/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:50:02 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/16 11:32:34 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

Base *generate(void)
{
	srand(time(NULL));
	int random_number = std::rand() % 3;	

	if (random_number == 0)
		return new A;
	else if (random_number == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A class (from pointer)" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B class (from pointer)" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C class (from pointer)" << std::endl;
	else
		std::cout << "what is this câlice" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		A& a_ptr = dynamic_cast<A&>(p);
		(void)a_ptr;
		std::cout << "A class (from reference)" << std::endl;
	} 
	catch (std::exception) 
	{
		// std::cout << " Dynamic cast in A failed" << std::endl;
	}

	try 
	{
		B& b_ptr = dynamic_cast<B&>(p);
		(void)b_ptr;
		std::cout << "B class (from reference)" << std::endl;
	} 
	catch (std::exception) 
	{
		// std::cout << " Dynamic cast in B failed" << std::endl;
	}

	try 
	{
		C& c_ptr = dynamic_cast<C&>(p);
		(void)c_ptr;
		std::cout << "C class (from reference)" << std::endl;
	} 
	catch (std::exception) 
	{
		// std::cout << " Dynamic cast in C failed" << std::endl;
	}
}

int main(void)
{
	std::cout << "----------TEST WITH A----------" << std::endl;
	Base* test_A = new A;
	identify(test_A);
	identify(*test_A);
	delete test_A;

	std::cout << std::endl << "----------TEST WITH B----------" << std::endl;

	Base* test_B = new B;
	identify(test_B);
	identify(*test_B);
	delete test_B;

	std::cout << std::endl << "----------TEST WITH C----------" << std::endl;

	Base* test_C = new C;
	identify(test_C);
	identify(*test_C);
	delete test_C;
	
	std::cout << std::endl << "----------TEST WITH NULL----------" << std::endl;

	identify(NULL);
	identify(NULL);

	// std::cout << std::endl << "----------TEST WITH RANDOM----------" << std::endl;
	// Base *random[10];
	
	// for (int i = 0; i < 10; i++)
	// {
	// 	random[i] = generate();
	// 	sleep(1); //mandatory for the randomize that use time
	// }
	// for (int i = 0; i < 10; i++)
	// {
	// 	identify(random[i]);
	// 	identify(*random[i]);
	// }
	// for (int i = 0; i < 10; i++)
	// 	delete random[i];
}