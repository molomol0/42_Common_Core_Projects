/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:45:25 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/12 10:16:22 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materia[4];
		int			_nb_materia;
	
	public:
		MateriaSource();
		MateriaSource(MateriaSource & copy);
		~MateriaSource();
		
		MateriaSource & operator=(MateriaSource &copy);

		void		learnMateria(AMateria*) override;
		AMateria*	createMateria(std::string const & type) override;

		void		printMateria() override;
};

#endif