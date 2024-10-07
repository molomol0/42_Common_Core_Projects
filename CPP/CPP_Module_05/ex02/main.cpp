/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:10:53 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/24 15:17:08 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    std::cout << "---CONSTRUCTORS---" << std::endl;
    ShrubberyCreationForm   shru_form("past");
    RobotomyRequestForm     robo_form("futur");
    PresidentialPardonForm  pres_form("present");

    Bureaucrat              president("President", 1);
    Bureaucrat              stagiaire("stagiaire", 150);
    Bureaucrat              manager("manager", 75);

    std::cout  << std::endl << "----------------" << std::endl;
    std::cout << "---BASIC-TESTS---" << std::endl << std::endl << std::endl;
    std::cout << "stagiaire tests sign forms" << std::endl << std::endl;
    try
    {
        stagiaire.signForm(shru_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        stagiaire.signForm(robo_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        stagiaire.signForm(pres_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "stagiaire test exec form -form already signed-" << std::endl << std::endl ;
    try
    {
        shru_form.beSigned(president);
        stagiaire.executeForm(shru_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        robo_form.beSigned(president);
        stagiaire.executeForm(robo_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        pres_form.beSigned(president);
        stagiaire.executeForm(pres_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl << "---test president execute all the forms---" << std::endl << std::endl;
    try
    {
        president.executeForm(shru_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        president.executeForm(pres_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        president.executeForm(robo_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl << "---tests with manager---" << std::endl << std::endl;
    try
    {
        manager.executeForm(robo_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        manager.executeForm(shru_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        manager.executeForm(pres_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "---increment manager grade x10---" << std::endl << std::endl;
    for (int i = 0; i < 10; i++)
        manager.incrementGrade();
    std::cout << manager << std::endl;
    try
    {
        manager.executeForm(pres_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "---increment manager grade x60---" << std::endl << std::endl;
    for (int i = 0; i < 60; i++)
        manager.incrementGrade();
    try
    {
        manager.executeForm(pres_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << manager << std::endl;
    std::cout << "---DESTRUCTOR---" << std::endl;
}