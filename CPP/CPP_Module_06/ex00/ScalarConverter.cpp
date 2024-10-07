/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 05:13:11 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/14 15:33:06 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

int isPoint(std::string str) 
{
	int count = 0;
	for (std::string::iterator it = str.begin(); it < str.end(); it++) {
		if (*it == '.')
			++count;
	}
	return count;
}

int isF(std::string str) 
{
	int count = 0;
	for (std::string::iterator it = str.begin(); it < str.end(); it++) {
		if (count)
			return -1;
		if (*it == 'f')
			++count;
	}
	if (count == 1)
		return 1;
	return 0;
}

int isUndef(std::string str) 
{
	for (std::string::iterator it = str.begin(); it < str.end(); it++) {
		if ((*it < '0' || *it > '9') && *it != '.') {
			if ((it != str.begin() && (*it == '+' || *it == '-')) || (*it != 'f' && *it != '+' && *it != '-'))
				return 1;
			if (isF(str) == -1)
				return 1;
		}
	}
	return 0;
}

int isNb(std::string str) 
{
	for (std::string::iterator it = str.begin(); it < str.end(); it++) {
		if ((it == str.begin() && ((*it != '+' && *it != '-') && (*it < '0' || *it > '9'))) || (it != str.begin() && (*it < '0' || *it > '9')) )
			return 0;
	}
	return 1;
}

Type getType(std::string str) 
{
	Type type;

	type = UNDEF;
	if (!str.compare("+inf") || !str.compare("-inf") || !str.compare("inff") || !str.compare("inf") || !str.compare("+inff") || !str.compare("-inff"))
		type = INF;
	else if (!str.compare("nan") || !str.compare("nanf"))
		type = NAN_T;
	else {
		if (str.length() == 1 && (str[0] < '0' || str[0] > '9'))
			type = CHAR;
		else {
			if (isPoint(str) == 0 && isF(str) && !isUndef(str) && str.find('f') == str.length() - 1 && str.compare("+f") && str.compare("-f"))
				type = FLOAT;
			else if (isNb(str))
				type = INT;
			else 
			{
				if (isF(str) && isPoint(str) == 1 && !isUndef(str) && str.find('f') == str.length() - 1)
					type = FLOAT;
				else if (isPoint(str) == 1 && !isUndef(str))
					type = DOUBLE;
			}
		}
	}
	return type;
}

void	undefConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	charConvert(std::string str)
{
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	intConvert(std::string str, char *char_str)
{
	(void)str;
	long i = std::atol(char_str);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	if (i > 2147483647 || i < -2147483648) {
		std::cout << char_str << " too big for an int" << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	floatConvert(std::string str, char *char_str)
{
	(void)str;
	float f = std::atof(char_str);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (f > static_cast<float>(2147483647) || f < static_cast<float>(-2147483648) )
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	doubleConvert(std::string str, char *char_str)
{
	(void)str;
	double d = std::strtod(char_str, NULL);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (d > 2147483647 || d < -2147483648 )
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
	std::cout << "float: ";
	if (d > __FLT_MAX__ || d < -__FLT_MAX__)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	infConvert(std::string str, char *char_str)
{
	(void)str;
	float f = std::atof(char_str);
	double d = std::strtod(char_str, NULL);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	nanConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	ScalarConverter::convert(char *argv)
{
	std::string str(argv);

	Type type = getType(str);

	switch (type)
	{
		case UNDEF :
			undefConvert();
			break;
			
		case CHAR :
			charConvert(str);
			break;
			
		case INT :
			intConvert(str, argv);
			break;

		case FLOAT :
			floatConvert(str, argv);
			break;

		case DOUBLE :
			doubleConvert(str, argv);
			break;

		case INF :
			infConvert(str, argv);
			break;

		case NAN_T :
			nanConvert();
			break;

		default :
			std::cout << "problem" << std::endl;
	}
}