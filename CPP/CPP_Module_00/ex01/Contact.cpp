/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 06:15:47 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/26 06:22:32 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string	Contact::get_first()
{
	return _first_name;
}

void	Contact::set_first(std::string first)
{
	this->_first_name = first;
}

std::string	Contact::get_last()
{
	return _last_name;
}

void	Contact::set_last(std::string last)
{
	this->_last_name = last;
}

std::string	Contact::get_nickname()
{
	return _nickname;
}

void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

std::string	Contact::get_phone()
{
	return _phone_number;
}

void	Contact::set_phone(std::string phone)
{
	this->_phone_number = phone;
}

std::string	Contact::get_secret()
{
	return _darkest_secret;
}

void	Contact::set_secret(std::string secret)
{
	this->_darkest_secret = secret;
}
