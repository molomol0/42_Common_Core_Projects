/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:11:52 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/24 17:14:08 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : _name("Default_name"), _signed(false) , _sign_grade(150), _exec_grade(150)
{
	std::cout << "Form Default Constructor" << std::endl;
}

Form::Form(std::string name) : _name(name), _signed(false) , _sign_grade(150), _exec_grade(150)
{
	std::cout << "Form Named Constructor" << std::endl;
}

Form::Form(int sign_grade) : _name("Default_name"), _signed(false) , _sign_grade(sign_grade), _exec_grade(sign_grade)
{
	std::cout << "Form Sign Graded Constructor" << std::endl;

	if (sign_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string name, int sign_grade) : _name(name), _signed(false) , _sign_grade(sign_grade), _exec_grade(sign_grade)
{
	std::cout << "Form Named & Sign Graded Constructor" << std::endl;
	
	if (sign_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(int sign_grade, int exec_grade) : _name("Default_name"), _signed(false) , _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Sign Graded & Exec Graded Constructor" << std::endl;
	
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false) , _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form All Parameter Constructor" << std::endl;
	
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form & copy) : _name(copy.getName()), _signed(false) , _sign_grade(copy.getSignGrade()), _exec_grade(copy.getExecGrade())
{
	std::cout << "Form Copy Constructor" << std::endl;
	
	*this = copy;
}

Form::~Form()
{
	std::cout << "Form Default Destructor" << std::endl;
}

Form & Form::operator=(Form & rhs)
{
	(void)rhs;
	return *this;
}

std::string	Form::getName() const
{
	return this->_name;
}

bool	Form::isSigned() const
{
	return this->_signed;
}

int		Form::getSignGrade() const
{
	return this->_sign_grade;
}

int		Form::getExecGrade() const
{
	return this->_exec_grade;
}

void	Form::beSigned(Bureaucrat & bureau)
{
	if (bureau.getGrade() > this->getSignGrade())
	{
		std::cout << bureau.getName() << " couldn't sign " << this->getName() << " because is grade was to low" << std::endl;
		throw Form::GradeTooLowException();
	}
	else if (this->_signed == true)
		std::cout << bureau.getName() << " couldn't sign " << this->getName() << " because it was already signed" << std::endl;
	else
	{
		this->_signed = true;
		std::cout << bureau.getName() << " signed " << this->getName() << std::endl;
	}	
}

std::ostream & operator<<(std::ostream & o, Form & form)
{
	o << "Form name : " << form.getName() << std::endl;
	if (form.isSigned() == true)
		o << "Form status : signed" << std::endl;
	else
		o << "Form status : unsigned" << std::endl;
	o << "Form sign level : " << form.getSignGrade() << std::endl;
	o << "Form execution level : " << form.getExecGrade() << std::endl;

	return o;
}