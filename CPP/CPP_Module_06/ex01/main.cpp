/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:35:13 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/14 13:35:39 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data test;
	Data *ptr = &test;
	
	uintptr_t raw = Serializer::serialize(ptr);
	Data *ptr_test = Serializer::deserialize(raw);

	std::cout << std::endl << "--------TEST WITH 5--------" << std::endl;
	test.data = 5;
	std::cout << test.data << std::endl;
	std::cout << ptr->data << std::endl;
	std::cout << ptr_test->data << std::endl;

	std::cout << std::endl << "--------TEST WITH 42--------" << std::endl;
	test.data = 42;
	std::cout << test.data << std::endl;
	std::cout << ptr->data << std::endl;
	std::cout << ptr_test->data << std::endl;

	std::cout << std::endl << "--------TEST WITH 0--------" << std::endl;
	test.data = 0;
	std::cout << test.data << std::endl;
	std::cout << ptr->data << std::endl;
	std::cout << ptr_test->data << std::endl;
}