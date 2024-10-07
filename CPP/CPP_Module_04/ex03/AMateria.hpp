/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:05 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/12 08:53:22 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria & copy);
		~AMateria();
		AMateria& operator=(AMateria & copy);

		std::string const & getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif