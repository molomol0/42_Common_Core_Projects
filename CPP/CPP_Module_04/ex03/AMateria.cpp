/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:47:43 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/12 13:56:43 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("Default_type")
{
	std::cout << "AMateria Default Constructor" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria Parametric Constructor" << std::endl;
	this->_type = type;
}

AMateria::AMateria(AMateria & copy)
{
	std::cout << "AMateria Copy Constructor" << std::endl;
	*this = copy;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Default Destructor" << std::endl;
}

AMateria & AMateria::operator=(AMateria & copy)
{
	this->_type = copy._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

AMateria* AMateria::clone() const
{
	return NULL;
}

void	AMateria::use(ICharacter& target)
{
}
