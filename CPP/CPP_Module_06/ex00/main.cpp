/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 05:07:11 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/07 08:28:10 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
	}
	else
	{
		std::cerr << "Usage : ./ex00 <value>" << std::endl;
	}
}
