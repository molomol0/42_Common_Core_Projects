#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

# include <iostream>
# include <string>

class Cat : public Animal
{

	public:

		Cat();
		Cat( Cat const & src );
		~Cat();

		Cat &		operator=( Cat const & rhs );

		Brain*		getBrain() const;

		void		makeSound() const;

		void		put_idea(std::string idea, int index);
		void		print_ideas(void) const;

	private:

		Brain*	_brain;

};

#endif /* ************************************************************* CAT_H */