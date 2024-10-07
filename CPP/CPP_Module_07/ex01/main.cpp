/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:21:18 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/17 13:34:18 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	std::cout << "------TEST WITH STRING------" << std::endl;
	std::string strings[3] = {"one", "two", "three"};
	::iter(strings, 3, display);

	std::cout << std::endl << "------TEST WITH INT------" << std::endl;
	int ints[3] = {1, 2, 3};
	::iter(ints, 3, display);

	std::cout << std::endl << "------TEST WITH FLOAT------" << std::endl;
	float floats[3] = {1.1, 2.2, 3.3};
	::iter(floats, 3, display);
	
	return 0;
}