/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:37:38 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/04 14:22:35 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::vector<int> 		vect( array, array + sizeof( array ) / sizeof( int ) );
    std::list< int >        list( array, array + sizeof( array ) / sizeof( int ) );
	
	std::cout << "-------TEST WITH VECTOR-------" << std::endl;
	std::cout << "---VALID TEST---" << std::endl;
	try
	{
		easyfind(vect, 4);
		easyfind(vect, 7);
	}
	catch (ValueNotFoundException e)
	{
		std::cout << e.what() << std::endl; 
	}

	std::cout << "---INVALID TEST---" << std::endl;
	try
	{
		easyfind(vect, -1);
	}
	catch (ValueNotFoundException e)
	{
		std::cout << e.what() << std::endl; 
	}

	try
	{
		easyfind(vect, 42);
	}
	catch (ValueNotFoundException e)
	{
		std::cout << e.what() << std::endl; 
	}

	std::cout << std::endl << "-------TEST WITH LIST-------" << std::endl;
	std::cout << "---VALID TEST---" << std::endl;
	try
	{
		easyfind(list, 4);
		easyfind(list, 2);
	}
	catch (ValueNotFoundException e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "---INVALID TEST---" << std::endl;
	try
	{
		easyfind(vect, 0);
	}
	catch (ValueNotFoundException e)
	{
		std::cout << e.what() << std::endl; 
	}

	try
	{
		easyfind(vect, 2147483647);
	}
	catch (ValueNotFoundException e)
	{
		std::cout << e.what() << std::endl; 
	}

}