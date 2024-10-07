/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:37:38 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/04 19:35:50 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>

class Span
{
	private:
		unsigned int	_max_int;
		std::list<int>	_list;
		Span();

	public:
		Span(unsigned int);
		Span(const Span &);
		~Span();

		Span & operator=(Span const &);

		unsigned int getMaxInt() const;
		const std::list<int> getList() const;

		void	addNumber(int);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();

		class TooFewSpace : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Not enough space in the list";
			}
		};

		class TooFewElement : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Not enough element in the list";
			}
		};
};