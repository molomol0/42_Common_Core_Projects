/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:43:41 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/07 16:14:02 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T, class Container = std::deque<T> >

class MutantStack: public std::stack<T, Container>
{
    private:
           
    public:
        MutantStack(): std::stack<T, Container>(){};
        MutantStack(const Container &cont) : std::stack<T, Container>(cont){};
        ~MutantStack(){};
        MutantStack(const MutantStack &to_copy)
        {
            *this = to_copy;
            return ;
        }
        MutantStack &operator=(const MutantStack &to_copy)
        {
            std::stack<T, Container>::operator=(to_copy);
            return (*this);
        }
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator    begin()
        {
            return (std::stack<T, Container>::c.begin());
        }
        iterator    end()
        {
            return (std::stack<T, Container>::c.end());
        }
};