/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:42:52 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/22 19:24:14 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

#include "AForm.hpp"

class	AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
	
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Exception Bureaucrat Grade Too High !");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Exception Bureaucrat Grade Too Low !");
				}
		};
		
		Bureaucrat();
		Bureaucrat(std::string);
		Bureaucrat(int);
		Bureaucrat(std::string, int);
		Bureaucrat(Bureaucrat &);
		~Bureaucrat();

		Bureaucrat& operator=(Bureaucrat &);

		std::string		getName() const;
		int				getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
		void			signForm(AForm & form);

		void			executeForm(AForm const & form);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat & bureau);

#endif