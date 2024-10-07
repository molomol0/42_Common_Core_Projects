/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 06:39:51 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/26 08:18:39 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook book;
	std::string input = "";

	while (input.compare("EXIT"))
	{
		if (!input.compare("ADD"))
			book.add();
		else if (!input.compare("SEARCH"))
			book.search();
		std::cout << "> " << std::flush;
        std::cin >> input;
	}
	return (0);
}