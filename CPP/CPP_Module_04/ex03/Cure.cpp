/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:53:10 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/08 16:23:02 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure Default Constructor" << std::endl;
}

Cure::Cure(Cure &copy): AMateria(copy)
{
	std::cout << "Cure Copy Constructor" << std::endl;
	*this = copy;
}

Cure::~Cure()
{
	std::cout << "Cure Default Destructor" << std::endl;
}

Cure & Cure::operator=(AMateria &copy)
{
	std::cout << "Cure Assignation Operator" << std::endl;
	this->_type = copy.getType();
	return *this;
}

AMateria* Cure::clone() const
{
	std::cout << "Cure Clone" << std::endl;
	AMateria *clone = new Cure();
	return (clone);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
