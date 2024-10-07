/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:10:53 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/24 15:19:09 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "---CONSTRUCTORS---" << std::endl;
    AForm *test_shru;
    AForm *err_shru;
    AForm *test_pres;
    AForm *err_pres;
    AForm *test_robo;
    AForm *err_robo;
    Intern intern;
    Bureaucrat bur("Bureaucrat", 1);

    std::cout << std::endl << "---VALID TESTS---" << std::endl << std::endl;
    test_shru = intern.makeForm("shrubbery creation", "Shrubbery");
    std::cout << *test_shru << std::endl;
    bur.signForm(*test_shru);
    bur.executeForm(*test_shru);

    test_pres = intern.makeForm("presidential pardon", "President");
    std::cout << *test_pres << std::endl;
    bur.signForm(*test_pres);
    bur.executeForm(*test_pres);

    test_robo = intern.makeForm("robotomy request", "Robot");
    std::cout << *test_robo << std::endl;
    bur.signForm(*test_robo);
    bur.executeForm(*test_robo);

    
    std::cout << std::endl << "---INVALID TESTS---" << std::endl << std::endl;
    err_shru = intern.makeForm("shrubbery", "Shrubbery");

    err_pres = intern.makeForm("presidential", "President");

    err_robo = intern.makeForm("robotomy", "Robot");

    delete test_shru;
    delete test_pres;
    delete test_robo;
    
    std::cout << std::endl << "---Destructor---" << std::endl;
}