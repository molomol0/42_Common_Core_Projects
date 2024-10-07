/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:18:24 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/24 16:55:24 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor" << std::endl;
}

Intern::Intern(Intern & copy)
{
	std::cout << "Intern Copy Constructor" << std::endl;
	(void)copy;
	
	*this = copy;
}

Intern::~Intern()
{
	std::cout << "Intern Default Destructor" << std::endl;
}

Intern& Intern::operator=(Intern & op)
{
	std::cout << "Intern Assignation Operator" << std::endl;
	(void)op;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string request[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	int i = 0;
	while (i < 3)
	{
		if (name == request[i])
			break;
		i++;
	}

	switch(i)
	{
		case 0:
		{
			std::cout << "Intern creates " << name << std::endl;
			return new ShrubberyCreationForm(target);
		}
		case 1:
		{
			std::cout << "Intern creates " << name << std::endl;
			return new RobotomyRequestForm(target);
		}
		case 2:
		{
			std::cout << "Intern creates " << name << std::endl;
			return new PresidentialPardonForm(target);
		}
		default:
		{
			std::cout << "Intern can't create " << name << std::endl;
			return NULL;
		}
	}
}