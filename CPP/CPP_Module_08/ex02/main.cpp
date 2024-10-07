/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:15:00 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/07 16:38:15 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "-------TEST WITH MUTANTSTACK-------" << std::endl << std::endl;
	MutantStack<int> mstack;
	std::cout << "--push of two values (5 & 17)--" << std::endl << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Value at the top : " << mstack.top() << std::endl << std::endl;
	std::cout << "--pop of the top value--" << std::endl << std::endl;
	mstack.pop();
	std::cout << "Size of the stack : " << mstack.size() << std::endl << std::endl;
	std::cout << "--push of four values (3, 42, 737 , 0)--" << std::endl << std::endl;
	mstack.push(3);
	mstack.push(42);
	mstack.push(737);
	mstack.push(0);
	std::cout << "--display of the stack between the first value (" << *mstack.begin() << ") & the last (" << *mstack.end() << ")" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl << "-------TEST WITH LIST-------" << std::endl << std::endl;
	std::list<int> lis;
	std::cout << "--push back of two values (5 & 17)--" << std::endl << std::endl;
	lis.push_back(5);
	lis.push_back(17);
	std::cout << "Value at the back : " << lis.back() << std::endl << std::endl;
	std::cout << "--pop back of the back value--" << std::endl << std::endl;
	lis.pop_back();
	std::cout << "Size of the list : " << lis.size() << std::endl << std::endl;
	std::cout << "--push back of four values (3, 42, 737 , 0)--" << std::endl << std::endl;
	lis.push_back(3);
	lis.push_back(5);
	lis.push_back(737);
	lis.push_back(0);
	std::cout << "--display of the list between the first value (" << *lis.begin() << ") & the last (" << *lis.end() << ")" << std::endl;
	std::list<int>::iterator lit = lis.begin();
	std::list<int>::iterator lite = lis.end();
	++lit;
	--lit;
	while (lit != lite)
	{
	std::cout << *lit << std::endl;
	++lit;
	}
	return 0;
}