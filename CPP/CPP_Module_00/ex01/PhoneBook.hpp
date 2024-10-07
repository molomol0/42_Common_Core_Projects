/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:07:01 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/26 08:14:46 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>

class Contact {
	
	public:

		Contact();
		~Contact();
		
		std::string	get_first();
		void	set_first(std::string);
		std::string	get_last();
		void	set_last(std::string);
		std::string	get_nickname();
		void	set_nickname(std::string);
		std::string	get_phone();
		void	set_phone(std::string);
		std::string	get_secret();
		void	set_secret(std::string);
	
	private:

		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
	
};

class PhoneBook {

	public:

		PhoneBook();
		~PhoneBook();

		Contact*	get_contacts();
		void		set_contacts(Contact);
		void		add(void);
		std::string	get_input(std::string);
		void		search(void);
		void		print_detailed_contact(int);
		void		print_contacts(void);
		void		print_column(std::string);
		void		print_header(void);

	private:

		Contact		_contacts[8];
		int			_nb_contacts;
};

#endif