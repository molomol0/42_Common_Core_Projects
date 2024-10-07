/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:07:39 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/22 19:32:51 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default_target")
{
	std::cout << "RobotomyRequestForm Default Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Named Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm & copy) : AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Default Destructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm & op)
{
	std::cout << "RobotomyRequestForm Assignation Operator" << std::endl;
	(void)op;
	return *this;
}

void	RobotomyRequestForm::action() const
{
	int random_number = std::rand() % 2;

	if (random_number == 0)
		std::cout << "** Drilling noises **" << std::endl << this->_target << " has been robotomized successfully :)" << std::endl;
	else
		std::cout << "** Drilling noises **" << std::endl << this->_target << " has not been robotomized :(" << std::endl;
}
