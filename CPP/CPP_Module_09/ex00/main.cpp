/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:24:55 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/18 16:25:35 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	const char *data_file = "data.csv";

	std::multimap<std::string, float>	map_input;
	std::map<std::string, float>		map_data;

	if (argc != 2)
	{
		std::cerr << "Usage : ./btc <file>" << std::endl;
		return 1;
	}

	try 
	{
		map_data = create_map_data(data_file);
	}
	catch (CantOpenFileException e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		convert_bitcoin(map_data, argv[1]);
	}
	catch (CantOpenFileException e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}