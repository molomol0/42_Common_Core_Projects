/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:06:40 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/17 13:12:38 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> void swap(T &a, T &b)
{
	T tmp = a;
	
	a = b;
	b = tmp;
}

template <typename T> T max(T a, T b)
{
	if (a > b)
		return a;
	return b;
}

template <typename T> T min(T a, T b)
{
	if (a < b)
		return a;
	return b;
}
