/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:10:53 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/26 16:39:33 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		//Normal Constructor
		Bureaucrat empty;
		std::cout << empty << std::endl;

		Bureaucrat Marie("Marie");
		std::cout << Marie << std::endl;
		
		Bureaucrat Antoinette(Marie);
		std::cout << Antoinette << std::endl;

		Bureaucrat Toulouse(1);
		std::cout << Toulouse << std::endl;
	
		Bureaucrat Berlioz("Berlioz", 150);
		std::cout << Berlioz << std::endl;

		//Error Constructor
		// Bureaucrat Low(160);
		// Bureaucrat Hight ("high", 0);

		//Error Action
		// Toulouse.incrementGrade();
		// Berlioz.decrementGrade();

		//Normal Action
		Toulouse.decrementGrade();
		Berlioz.incrementGrade();

		std::cout << Toulouse << std::endl;
		std::cout << Berlioz << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}