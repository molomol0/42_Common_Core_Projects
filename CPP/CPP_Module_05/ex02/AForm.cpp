/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:11:52 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/22 14:28:06 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() : _name("Default_name"), _signed(false) , _sign_grade(150), _exec_grade(150)
{
	std::cout << "AForm Default Constructor" << std::endl;
}

AForm::AForm(std::string name) : _name(name), _signed(false) , _sign_grade(150), _exec_grade(150)
{
	std::cout << "AForm Named Constructor" << std::endl;
}

AForm::AForm(int sign_grade) : _name("Default_name"), _signed(false) , _sign_grade(sign_grade), _exec_grade(sign_grade)
{
	std::cout << "AForm Sign Graded Constructor" << std::endl;

	if (sign_grade < 1)
		throw AForm::GradeTooHighException();
	else if (sign_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int sign_grade) : _name(name), _signed(false) , _sign_grade(sign_grade), _exec_grade(sign_grade)
{
	std::cout << "AForm Named & Sign Graded Constructor" << std::endl;
	
	if (sign_grade < 1)
		throw AForm::GradeTooHighException();
	else if (sign_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(int sign_grade, int exec_grade) : _name("Default_name"), _signed(false) , _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm Sign Graded & Exec Graded Constructor" << std::endl;
	
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false) , _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm All Parameter Constructor" << std::endl;
	
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm & copy) : _name(copy.getName()), _signed(false) , _sign_grade(copy.getSignGrade()), _exec_grade(copy.getExecGrade())
{
	std::cout << "AForm Copy Constructor" << std::endl;
	
	*this = copy;
}

AForm::~AForm()
{
	std::cout << "AForm Default Destructor" << std::endl;
}

AForm & AForm::operator=(AForm & rhs)
{
	(void)rhs;
	return *this;
}

std::string	AForm::getName() const
{
	return this->_name;
}

bool	AForm::isSigned() const
{
	return this->_signed;
}

int		AForm::getSignGrade() const
{
	return this->_sign_grade;
}

int		AForm::getExecGrade() const
{
	return this->_exec_grade;
}

void	AForm::beSigned(Bureaucrat & bureau)
{
	if (bureau.getGrade() > this->getSignGrade())
	{
		std::cout << bureau.getName() << " couldn't sign " << this->getName() << " because is grade was to low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else if (this->_signed == true)
		std::cout << bureau.getName() << " couldn't sign " << this->getName() << " because it was already signed" << std::endl;
	else
	{
		this->_signed = true;
		std::cout << bureau.getName() << " signed " << this->getName() << std::endl;
	}	
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
	{
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because is grade was to low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else if (this->_signed == false)
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because it was not signed" << std::endl;
	else
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		this->action();
	}
}

std::ostream & operator<<(std::ostream & o, AForm & form)
{
	o << "AForm name : " << form.getName() << std::endl;
	if (form.isSigned() == true)
		o << "AForm status : signed" << std::endl;
	else
		o << "AForm status : unsigned" << std::endl;
	o << "AForm sign level : " << form.getSignGrade() << std::endl;
	o << "AForm execution level : " << form.getExecGrade() << std::endl;

	return o;
}