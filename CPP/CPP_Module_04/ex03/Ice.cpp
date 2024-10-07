/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:23:12 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/12 13:40:41 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice Default Constructor" << std::endl;
}

Ice::Ice(Ice &copy): AMateria(copy)
{
	std::cout << "Ice Copy Constructor" << std::endl;
	*this = copy;
}

Ice::~Ice()
{
	std::cout << "Ice Default Destructor" << std::endl;
}

Ice & Ice::operator=(AMateria &copy)
{
	std::cout << "Ice Assignation Operator" << std::endl;
	this->_type = copy.getType();
	return *this;
}

AMateria* Ice::clone() const
{
	std::cout << "Ice Clone" << std::endl;
	AMateria *clone = new Ice();
	return (clone);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
