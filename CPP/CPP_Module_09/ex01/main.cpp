/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:13:23 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/18 17:16:54 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN <string>" << std::endl;
		return 1;
	}

	if (isInputValid(argv[1]) == false)
	{
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}
	else
		calculate(argv[1]);

	return 0;
}