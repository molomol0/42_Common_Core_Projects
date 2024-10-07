/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:29:45 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/22 14:49:48 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int index = 1;
	int index2 = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[index])
		{
			index2 = 0;
			while (argv[index][index2])
			{
				std::cout << (char) toupper(argv[index][index2]);
				index2++;
			}
			index++;
		}
		std::cout << std::endl;
	}
	return (0);
}