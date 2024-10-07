/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:37:38 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/04 19:40:40 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <vector>
#include <cmath>

Span::Span(unsigned int n): _max_int(n)
{
}

Span::Span(const Span & copy): _max_int(copy.getMaxInt()), _list(copy.getList())
{
}

Span::~Span()
{
}

Span & Span::operator=(Span const & rhs)
{
	this->_list = rhs.getList();
	this->_max_int = rhs.getMaxInt();

	return *this;
}

unsigned int Span::getMaxInt() const
{
	return this->_max_int;
}

const std::list<int> Span::getList() const
{
	return this->_list;
}

void	Span::addNumber(int number)
{
	if (this->_list.size() >= this->_max_int)
		throw TooFewSpace();
	else
		this->_list.push_back(number);
}

unsigned int		Span::shortestSpan()
{
		unsigned int current;
		unsigned int minimum;

		if (this->_list.size() < 2)
			throw TooFewElement();

		std::vector<int> copy(this->_list.begin(), this->_list.end());

		std::stable_sort(copy.begin(), copy.end());

		minimum = std::abs(copy[1] - copy[0]);

		for (size_t i = 1; i < copy.size() - 1; ++i)
		{
			current = std::abs(copy[i+1] - copy[i]);
			if (current < minimum)
				minimum = current;
		}
		return minimum;
}

unsigned int		Span::longestSpan()
{
	if (this->_list.size() < 2)
		throw TooFewElement();
	else
	{
		int max = *std::max_element(this->_list.begin(), this->_list.end());
		int min = *std::min_element(this->_list.begin(), this->_list.end());

		return std::abs(max - min);
	}
}
