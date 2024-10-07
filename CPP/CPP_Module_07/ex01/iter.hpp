/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:21:16 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/17 14:54:36 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T> void iter(T array[], std::size_t length, void (*func)(T))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T> void display(T param)
{
	std::cout << param << std::endl;
}
