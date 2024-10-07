/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:15:03 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/08 16:22:24 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		Cure(Cure &copy);
		~Cure();
		Cure& operator=(AMateria &copy);
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif