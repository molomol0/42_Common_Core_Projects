/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:25:06 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/13 18:49:37 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>

int getPrecision(float number) 
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(6) << number;
    std::string s = ss.str();

    std::size_t dotPosition = s.find('.');
    if (dotPosition == std::string::npos) 
        return 0;

    int precision = 0;
    for (std::size_t i = s.length() - 1; i > dotPosition; --i) 
	{
        if (s[i] != '0') 
		{
            precision = i - dotPosition;
            break;
        }
    }

    if (precision > 5) 
        precision = 5;

    return precision;
}

std::map<std::string, float>	create_map_data(const char *file)
{
	std::map<std::string, float>	map;
	std::ifstream				ifs;
	std::string					line;
	std::string					key;
	float						value;

	ifs.open(file);
	if (!ifs.is_open())
	{
		throw CantOpenFileException();
	}
	while (std::getline(ifs, line))
	{
		std::string::size_type pos = line.find(",");
        if (pos != std::string::npos)
        {
            key = line.substr(0, pos);
            std::istringstream iss(line.substr(pos + 1));
            iss >> value;
          	map[key] = value;
        }
	}
	ifs.close();
	return map;
}

bool	isOnlyDigits(const std::string &str)
{
	return str.find_first_not_of("0123456789. -") == std::string::npos;
}

bool	isLeap(const std::string &str)
{
	int year;
	std::istringstream iss(str.substr(0, 4));
	iss >> year;
	int month;
	std::istringstream iss2(str.substr(5, 2));
	iss2 >> month;
	int day;
	std::istringstream iss3(str.substr(8, 2));
	iss3 >> day;
	

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			if (day > 29)
				return false;
		}
		else
		{
			if (day > 28)
				return false;
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	return true;
}

bool	isTooLate(const std::string &str)
{
	int year = 2022;
	int month = 4;
	int day = 0;

	int year2;
	std::istringstream iss(str.substr(0, 4));
	iss >> year2;
	int month2;
	std::istringstream iss2(str.substr(5, 2));
	iss2 >> month2;
	int day2;
	std::istringstream iss3(str.substr(8, 2));
	iss3 >> day2;

	if (year2 > year)
		return true;
	if (year2 == year && month2 > month)
		return true;
	if (year2 == year && month2 == month && day2 > day)
		return true;
	return false;
}

void	convert_bitcoin(std::map<std::string, float> map_data, char *input)
{
	std::ifstream				ifs;
	std::string					line;
	std::string					key;
	double						value;

	ifs.open(input);
	if (!ifs.is_open())
	{
		throw CantOpenFileException();
	}
	while (std::getline(ifs, line))
	{
		if (line == "" || line == "date | value")
			continue;
		std::string::size_type pos = line.find("|");
        if (pos != std::string::npos)
        {
            key = line.substr(0, pos);

			struct tm tm;
            if (strptime(key.c_str(), "%Y-%m-%d", &tm) == NULL || isLeap(key) == false)
            {
                std::cerr << "Error: invalid date format: " << key << std::endl;
                continue;
            }
			if (isTooLate(key) == true)
			{
				std::cerr << "Error: date is too late: " << key << std::endl;
				continue;
			}
			if (isOnlyDigits(line.substr(pos + 1)) == false)
			{
				std::cerr << "Error: invalid value: " << line.substr(pos + 1) << std::endl;
				continue;
			}
			std::istringstream iss(line.substr(pos + 1));
			if (!(iss >> value))
			{
				std::cerr << "Error: value is not a float: "<< value << std::endl;
				continue;
			}
			if (value < 0)
			{
				std::cerr << "Error: not a positive number" << std::endl;
				continue;
			}
			if (value > 1000)
			{
				std::cerr << "Error: too large a number" << std::endl;
				continue;
			}
	
			std::string modified_key = key.substr(0, key.size() - 1);
			std::map<std::string, float>::iterator it = map_data.lower_bound(modified_key);


			if (it == map_data.end() || it->first != modified_key)
            {
                if (it == map_data.begin())
                {
                    std::cerr << "Error: no valid date found for " << key << std::endl;
                    continue;
                }
                else
                {
                    it--;
                }
            }

			std::cout << key << " => " << std::setprecision(getPrecision(value)) << value << " = " << std::setprecision(getPrecision(value * it->second)) << std::fixed << value * it->second << std::endl;
		}
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
	ifs.close();
}
