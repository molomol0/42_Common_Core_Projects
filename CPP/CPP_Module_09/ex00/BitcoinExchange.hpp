/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:24:56 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/10 21:33:24 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <exception>

std::map<std::string, float>		create_map_data(const char *file);
void								convert_bitcoin(std::map<std::string, float>, char *input);

class CantOpenFileException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Error: could not open file";
		}
};

class NegativeValueException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Error: not a positive number";
		}
};

class TooBigValueException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Error: too large a number";
		}
};

// class InvalidDateException : public std::exception
// {
// 	private:
// 		std::string date;

// 	public:
// 		InvalidDateException(const std::string& date) : date(date) 
// 		{
// 		}

// 		const char* what() const throw()
// 		{
// 			return ("Error: invalid date format: " + date).c_str();
// 		}
// };