#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Brain.hpp"

#include <iostream>

class Animal
{
	public:

		Animal();
		Animal(Animal &animal);
		virtual ~Animal();

		Animal			&operator=(const Animal &animal);

		std::string		getType() const;
		void			setType(std::string type);

		Brain*			getBrain() const;

		virtual void	makeSound() const;

	protected:

		std::string _type;
};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif