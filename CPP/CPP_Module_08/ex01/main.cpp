/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:37:38 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/04 19:40:18 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	std::cout << "-------TEST WITH LIST OF 0-------" << std::endl;
	Span sp0 = Span(0);
	std::cout << "---INVALID TEST---" << std::endl;
	try
	{
		sp0.addNumber(6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp0.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp0.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span sp = Span(5);
	std::cout << std::endl << "-------TEST WITH LIST OF 5-------" << std::endl;
	std::cout << "---VALID TEST---" << std::endl;
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "---DUPLICATE TEST---" << std::endl;
	Span spDup = Span(5);
	try
	{
		spDup.addNumber(6);
		spDup.addNumber(3);
		spDup.addNumber(17);
		spDup.addNumber(9);
		spDup.addNumber(9);
		std::cout << spDup.shortestSpan() << std::endl;
		std::cout << spDup.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-------TEST WITH LIST OF 10000-------" << std::endl;
	Span sp30 = Span(30);
	int mult = 1;
	for (int i = 0; i < 30; i++)
	{
		sp30.addNumber(mult);
		mult *= 2;
	}
	std::cout << "---VALID TEST---" << std::endl;
	try
	{
		std::cout << sp30.shortestSpan() << std::endl;
		std::cout << sp30.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "-------TEST WITH LIST OF 100000-------" << std::endl;
	Span sp100000 = Span(100000);
	for (int i = 0; i < 100000; i++)
	{
		sp100000.addNumber(i);
	}
	std::cout << "---VALID TEST---" << std::endl;
	try
	{
		std::cout << sp100000.shortestSpan() << std::endl;
		std::cout << sp100000.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "---INVALID TEST---" << std::endl;
	try
	{
		sp100000.addNumber(6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}