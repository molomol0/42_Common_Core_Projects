/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:44:17 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/19 18:16:28 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

# include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm
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
					return ("Exception AForm Grade Too High !");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Exception AForm Grade Too Low !");
				}
		};
		
		AForm();
		AForm(std::string name);
		AForm(int sign_grade);
		AForm(std::string name, int sign_grade);
		AForm(int sign_grade, int exec_grade);
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(AForm & copy);
		virtual ~AForm();

		AForm& operator=(AForm &);

		std::string		getName() const;
		bool			isSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;

		void			beSigned(Bureaucrat & bureau);

		void			execute(Bureaucrat const & executor) const;
		virtual void	action() const = 0;
};

std::ostream & operator<<(std::ostream & o, AForm & form);
#endif