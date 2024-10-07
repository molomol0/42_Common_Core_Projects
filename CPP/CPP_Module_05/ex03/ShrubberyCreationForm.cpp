/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:07:39 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/22 19:36:01 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default_target")
{
	std::cout << "ShrubberyCreationForm Default Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Named Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & copy) : AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Default Destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm & op)
{
	std::cout << "ShrubberyCreationForm Assignation Operator" << std::endl;
	(void)op;
	return *this;
}

void	ShrubberyCreationForm::action() const
{
	std::string filename = _target + "_shrubbery";
	
	std::ofstream file(filename.c_str());

    if (file.is_open()) 
	{
		file << "      /\\      " << std::endl;
		file << "     /\\*\\     " << std::endl;
		file << "    /\\O\\*\\    " << std::endl;
		file << "   /*/\\/\\/\\   " << std::endl;
		file << "  /\\O\\/\\*\\/\\  " << std::endl;
		file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << std::endl;
        file.close();
    } 
	else 
	{
        std::cerr << "Error while opening file" << std::endl;
    }
}
