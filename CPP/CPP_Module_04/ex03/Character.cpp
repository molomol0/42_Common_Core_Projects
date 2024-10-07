/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:39:09 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/15 15:30:45 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character(): _name("Default_name"), _nb_materia(0)
{
	std::cout << "Character Default Constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character(std::string name) : _name(name), _nb_materia(0)
{
	std::cout << "Character Parametric Constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character(Character & copy)
{
	std::cout << "Character Copy Constructor" << std::endl;
	*this = copy;
}

Character::~Character()
{
	std::cout << "Character Default Destructor" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_materia[i];
}

Character & Character::operator=(Character & copy)
{
	std::cout << "Character Assignation Operator" << std::endl;
	this->_name = copy.getName();
	this->_nb_materia = copy.getNbMateria();
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL)
			this->_materia[i] = copy._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
		std::cout << "Can't equip materia, materia is NULL" << std::endl;
	else if (this->_nb_materia == 4)
	{
		std::cout << "Can't equip materia, inventory full" << std::endl;
		delete m;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i] == m)
			{
				std::cout << "Can't equip materia, materia already in inventory" << std::endl;
				return ;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i] == NULL)
			{
				this->_materia[i] = m;
				this->_nb_materia++;
				return ;
			}
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Can't unequip materia, invalid index" << std::endl;
	}
	else if (this->_nb_materia == 0)
	{
		std::cout << "Can't unequip materia, inventory already empty" << std::endl;
	}
	else if (this->_materia[idx] == NULL)
	{
		std::cout << "Can't unequip materia, index is an empty inventory slot" << std::endl;
	}
	else
	{
		this->_materia[idx] = NULL;
		this->_nb_materia--;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Can't use materia, invalid index" << std::endl;
	else if (idx + 1 > this->_nb_materia || this->_materia[idx] == NULL)
		std::cout << "Can't use materia, index is an empty inventory slot" << std::endl;
	else
		this->_materia[idx]->use(target);
}

int		Character::getNbMateria()
{
	return this->_nb_materia;
}

void	Character::printChara()
{
	std::cout << "Character name: " << this->_name << std::endl;
	std::cout << "Character inventory: " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
			std::cout << "Inventory slot " << i << ": Empty" << std::endl;
		else
			std::cout << "Inventory slot " << i << ": " << this->_materia[i]->getType() << std::endl;

	}
}