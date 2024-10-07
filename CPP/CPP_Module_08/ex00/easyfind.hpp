/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:37:38 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/04 18:04:15 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>

class ValueNotFoundException : public std::exception {
public:
   	virtual const char* what() const throw()
	{
        return "Value not found";
    }
};

template <typename T> void easyfind(T& container, int value)
{
	if (std::find(container.begin(), container.end(), value) != container.end())
		std::cout << "Value found" << std::endl;
	else
		throw ValueNotFoundException();		
}