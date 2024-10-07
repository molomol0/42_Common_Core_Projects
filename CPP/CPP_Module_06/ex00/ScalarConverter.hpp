/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 05:13:04 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/14 13:54:37 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
#	include <cstdlib>

enum Type {
	UNDEF,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INF,
	NAN_T,
};

class ScalarConverter
{
	public:
		static void	convert(char *str);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & copy);
		~ScalarConverter();
		
		ScalarConverter &operator=(ScalarConverter & rhs);
};