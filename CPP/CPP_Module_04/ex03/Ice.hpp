/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:15:21 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/08 16:24:09 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice(Ice &copy);
		~Ice();
		Ice& operator=(AMateria &copy);
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif