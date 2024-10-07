/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:46:04 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/15 15:03:52 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _nb_materia(0)
{
	std::cout << "MateriaSource Default Constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource & copy)
{
	std::cout << "MateriaSource Copy Constructor" << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Default Destructor" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_materia[i];
}

MateriaSource& MateriaSource::operator=(MateriaSource &copy)
{
	std::cout << "MateriaSource Assignation Operator" << std::endl;
	for (int i = 0; i < copy._nb_materia; i++)
	{
		if (this->_materia[i] != NULL)
			_materia[i] = copy._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	
	}
	_nb_materia = copy._nb_materia;
	return *this;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (this->_nb_materia == 4)
		std::cout << "Can't learn materia, inventory full" << std::endl;
	else
	{
		this->_materia[this->_nb_materia] = materia;
		this->_nb_materia++;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	AMateria *creation;

	if (this->_nb_materia == 0)
	{
		std::cout << "Can't create materia, inventory empty" << std::endl;
		return 0;
	}
	else if (type != "ice" && type != "cure")
	{
		std::cout << "Can't create materia, unkown type" << std::endl;
		return 0;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	std::cout << "Can't create materia, type not in inventory" << std::endl;
	return 0;
}

void	MateriaSource::printMateria()
{
	std::cout << "MateriaSource inventory:" << std::endl;
	for (int i = 0; i < this->_nb_materia; i++)
		std::cout << this->_materia[i]->getType() << std::endl;
	std::cout << std::endl;
}