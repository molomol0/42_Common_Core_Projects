/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:07:39 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/22 19:19:18 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default_target")
{
	std::cout << "PresidentialPardonForm Default Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Named Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & copy) : AForm(copy), _target(copy._target)
{
	std::cout << "PresidentialPardonForm Copy Constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Default Destructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm & op)
{
	std::cout << "PresidentialPardonForm Assignation Operator" << std::endl;
	(void)op;
	return *this;
}

void	PresidentialPardonForm::action() const
{
	std::cout << "In his immense wisdom, the President of the Galaxy has decided to pardon " << this->_target << std::endl;
}
