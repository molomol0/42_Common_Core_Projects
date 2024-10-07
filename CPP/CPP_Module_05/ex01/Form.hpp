/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:44:17 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/22 17:00:50 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

# include "Bureaucrat.hpp"

class	Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;

	public:
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Exception Form Grade Too High !");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Exception Form Grade Too Low !");
				}
		};
		
		Form();
		Form(std::string name);
		Form(int sign_grade);
		Form(std::string name, int sign_grade);
		Form(int sign_grade, int exec_grade);
		Form(std::string name, int sign_grade, int exec_grade);
		Form(Form & copy);
		~Form();

		Form& operator=(Form &);

		std::string		getName() const;
		bool			isSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;

		void				beSigned(Bureaucrat & bureau);
};

std::ostream & operator<<(std::ostream & o, Form & form);
#endif