/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:39:25 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/12 10:16:53 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria*	_materia[4];
		int			_nb_materia;
	
	public:
		Character();
		Character(std::string);
		Character(Character & copy);
		~Character();
		
		Character & operator=(Character &copy);

		std::string const & getName() const override;
		void		equip(AMateria* m) override;
		void		unequip(int idx) override;
		void		use(int idx, ICharacter& target) override;

		int			getNbMateria();
		void		printChara() override;
};

#endif