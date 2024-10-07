/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:42:22 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/24 16:54:04 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default_name"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
	std::cout << "Bureaucrat Named Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default_name")
{
	std::cout << "Bureaucrat Graded Constructor" << std::endl;

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat Named & Graded Constructor" << std::endl;
	
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat & copy) : _name(copy.getName())
{
	std::cout << "Bureaucrat Copy Constructor" << std::endl;
	
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Default Destructor" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat & rhs)
{
	std::cout << "Bureaucrat Assignation Operator" << std::endl;	

	this->_grade = rhs.getGrade();
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::signForm(Form & form)
{
	form.beSigned(*this); 
}

std::ostream & operator<<(std::ostream & o, Bureaucrat & bureau)
{
	o << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << std::endl;
	return o;
}
