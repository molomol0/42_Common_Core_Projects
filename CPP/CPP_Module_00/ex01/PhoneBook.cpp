/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:07:18 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/26 08:34:38 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_nb_contacts = 0;
}

PhoneBook::~PhoneBook()
{
}

Contact*	PhoneBook::get_contacts()
{
	return _contacts;
}

void	PhoneBook::set_contacts(Contact new_contact)
{
	int	tmp = 0;

	if (this->_nb_contacts < 8)
	{
		this->_contacts[this->_nb_contacts] = new_contact;
		this->_nb_contacts++;
	}
	else
	{
		while (tmp < this->_nb_contacts - 1)
		{
			this->_contacts[tmp] = this->_contacts[tmp + 1];
			tmp++;
		}
		this->_contacts[7] = new_contact;
	}
}

std::string	PhoneBook::get_input(std::string str)
{
	std::string	input = "";
	bool        valid = false;
    do
    {
        std::cout << str;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = true;
        else 
		{
            std::cin.clear();
            std::cout << "Invalid input please try again." << std::endl;
        }
    } while (!valid);
    return (input);
}

void	PhoneBook::add(void)
{
	Contact		new_contact;
	std::string	tmp;

	std::cout << "--ADD--" << std::endl << std::endl;
	std::cin.ignore();
	new_contact.Contact::set_first(get_input("please enter a first name for your new contact : "));
	new_contact.Contact::set_last(get_input("please enter a last name for your new contact : "));
	new_contact.Contact::set_nickname(get_input("please enter a nickname for your new contact : "));
	new_contact.Contact::set_phone(get_input("please enter a phone number for your new contact : "));
	new_contact.Contact::set_secret(get_input("please enter a secret for your new contact : "));
	set_contacts(new_contact);
	std::cout << std::endl << "Contact added !" << std::endl;
}

void	PhoneBook::search(void)
{
	std::cout << "--SEARCH--" << std::endl << std::endl;
	print_contacts();
	std::cin.ignore();
	std::string input = get_input("Choose a contact's index : ");
	if (input.size() > 1 || input[0] < '1' || input[0] > std::to_string(_nb_contacts)[0])
		std::cout << "invalid index" << std::endl;
	else 
		print_detailed_contact(std::stoi(input));
}

void	PhoneBook::print_detailed_contact(int index)
{
	std::cout << std::endl << "Detail info of contact " << index << std::endl << std::endl;
	std::cout << "First Name : " << this->_contacts[index - 1].Contact::get_first() << std::endl;
	std::cout << "Last Name : " << _contacts[index - 1].get_last() << std::endl;
	std::cout << "Nickname : " << _contacts[index - 1].get_nickname() << std::endl;
	std::cout << "Phone Number : " << _contacts[index - 1].get_phone() << std::endl;
	std::cout << "Darkest Secret : " << _contacts[index - 1].get_secret() << std::endl;
}

void	PhoneBook::print_contacts(void)
{
	int	index = 0;

	print_header();
	while (index < _nb_contacts)
	{
		std::cout << "|";
		print_column(std::to_string(index + 1));
		std::cout << "|";
		print_column(this->_contacts[index].Contact::get_first());
		std::cout << "|";
		print_column(this->_contacts[index].Contact::get_last());
		std::cout << "|";
		print_column(this->_contacts[index].Contact::get_nickname());
		std::cout << "|";
		std::cout << std::endl;
		std::cout << " -------------------------------------------";
		std::cout << std::endl;
		index ++;
	}
}

void		PhoneBook::print_column(std::string str)
{
	int len = str.size();
	if (len <= 10)
	{
		for (int i = 0; i < 10 - len; i++)
			std::cout << " ";
		std::cout << str;
	}
	else
	{
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".";
	}
}

void	PhoneBook::print_header(void)
{
	std::cout << " -------------------------------------------";
	std::cout << std::endl;
	std::cout << "|";
	print_column("INDEX");
	std::cout << "|";
	print_column("FIRST NAME");
	std::cout << "|";
	print_column("LAST NAME");
	std::cout << "|";
	print_column("NICKNAME");
	std::cout << "|";
	std::cout << std::endl;
	std::cout << " -------------------------------------------";
	std::cout << std::endl;
}
