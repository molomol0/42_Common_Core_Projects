/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:53:32 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/17 15:49:03 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T> class Array
{
	public:
		Array() : _array(new T), _size(0){}
		Array(unsigned int n) : _array(new T[n]),  _size(n){}
		Array(Array &copy): _array(new T[copy.size()]), _size(copy.size())
		{
			for (unsigned int i = 0; i < copy.size(); i++)
				this->_array[i] = copy._array[i];
		}
		~Array()
		{
			delete [] this->_array;	
		}
		
		Array & operator=(Array & rhs)
		{
			if (this == &rhs) 
				return *this;
			delete [] this->_array;
			this->_size = rhs._size;
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_array[i] = rhs._array[i];
			}
			return *this;
		}
		T &		operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw std::out_of_range("Index Too High");
			return this->_array[index];
		}

		unsigned int size() 
		{
			return this->_size;
		}
	
	private:
		T				*_array;
		unsigned int	_size;
};