/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:10:53 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/22 14:21:03 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat Toulouse("Toulouse", 1);
		// std::cout << Toulouse << std::endl;
	
		Bureaucrat Berlioz("Berlioz", 150);
		// std::cout << Berlioz << std::endl;

		Form Form_empty;
		std::cout << Form_empty << std::endl;
		
		Form name_only("test");
		std::cout << name_only << std::endl;

		Form sign_grade_only(1);
		std::cout << sign_grade_only << std::endl;

		Form name_sign_grade("test", 2);
		std::cout << name_sign_grade << std::endl;

		Form sign_exec_grade(3, 4);
		std::cout << sign_exec_grade << std::endl;

		Form all1("all1", 5, 6);
		std::cout << all1 << std::endl;

		Form all2("all2", 7, 8);
		std::cout << all2 << std::endl;

		Toulouse.signForm(all1);
		Toulouse.signForm(all1); //pas de throw d'exception 
		Berlioz.signForm(all2); //throw d'execption
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}