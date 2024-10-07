/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:53:43 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/17 15:52:45 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	std::cout << "------TEST WITH INT------" << std::endl;

	Array<int> arrayInt(4);
	for (int i = 0; i <= 3; i++)
		arrayInt[i] = i;

	std::cout << std::endl << "-Test without exception-" << std::endl;
	for (int i = 0; i <= 3; i++)
	{
		try
		{
			std::cout << arrayInt[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "-Test with exception-" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		try
		{
			std::cout << arrayInt[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "-Test copy constructor-" << std::endl;
	Array<int> copyArrayInt(arrayInt);
	for (int i = 0; i <= 3; i++)
	{
		try
		{
			std::cout << copyArrayInt[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "-Test assignation operator-" << std::endl;
	Array<int> assignArrayInt;
	assignArrayInt = arrayInt;
	for (int i = 0; i <= 3; i++)
	{
		try
		{
			std::cout << assignArrayInt[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << std::endl << "------TEST WITH STRING------" << std::endl;
	Array<std::string> arrayStr(4);
	arrayStr[0] = "zero";
	arrayStr[1] = "one";
	arrayStr[2] = "two";
	arrayStr[3] = "three";

	std::cout << std::endl << "-Test without exception-" << std::endl;
	for (int i = 0; i <= 3; i++)
	{
		try
		{
			std::cout << arrayStr[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "-Test with exception-" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		try
		{
			std::cout << arrayStr[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}