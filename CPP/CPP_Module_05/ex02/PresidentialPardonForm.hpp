/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:04:50 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/22 19:18:22 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm & copy);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(PresidentialPardonForm &);

		void	action() const;
};

#endif