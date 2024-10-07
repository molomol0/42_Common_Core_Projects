/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:09:17 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/17 13:20:22 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "whatever.hpp"

int main(void)
{
	std::cout << "------TEST WITH INT------" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "* Swap *" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl << "------TEST WITH DOUBLE------" << std::endl;
	double doubleA = 42.0;
	double doubleB = 73.0;
	std::cout << "doubleA = " << doubleA << ", doubleB = " << doubleB << std::endl;
	::swap(doubleA, doubleB);
	std::cout << "* Swap *" << std::endl;
	std::cout << "doubleA = " << doubleA << ", doubleB = " << doubleB << std::endl;
	std::cout << "min( doubleA, doubleB ) = " << ::min(doubleA, doubleB) << std::endl;
	std::cout << "max( doubleA, doubleB ) = " << ::max(doubleA, doubleB) << std::endl;

	std::cout << std::endl << "------TEST WITH FLOAT------" << std::endl;
	float floatA = 123.0f;
	float floatB = 456.0f;
	std::cout << "floatA = " << floatA << ", floatB = " << floatB << std::endl;
	::swap(floatA, floatB);
	std::cout << "* Swap *" << std::endl;
	std::cout << "floatA = " << floatA << ", floatB = " << floatB << std::endl;
	std::cout << "min( floatA, floatB ) = " << ::min(floatA, floatB) << std::endl;
	std::cout << "max( floatA, floatB ) = " << ::max(floatA, floatB) << std::endl;

	std::cout << std::endl << "------TEST WITH STRING------" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "* Swap *" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}