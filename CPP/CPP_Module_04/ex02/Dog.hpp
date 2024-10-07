#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

# include <iostream>
# include <string>

class Dog : public Animal
{

	public:

		Dog();
		Dog( Dog const & src );
		~Dog();

		Dog &		operator=( Dog const & rhs );

		Brain*		getBrain() const;

		void		makeSound() override;

		void		put_idea(std::string idea, int index);
		void		print_ideas(void) const;

	private:

		Brain*	_brain;

};

// std::ostream &			operator<<( std::ostream & o, Dog const & i );

#endif /* ************************************************************* DOG_H */