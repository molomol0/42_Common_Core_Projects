#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->setType("Cat");
	this->_brain = new Brain();
}

Cat::Cat( const Cat & src )
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->_brain = new Brain(*(src.getBrain()));
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat Default Destructor called" << std::endl;
	if (this->_brain)
		delete(this->_brain);
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &			Cat::operator=( Cat const & rhs )
{
	this->_type = rhs.getType();
	this->_brain = rhs.getBrain();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::makeSound(void) const
{
	std::cout << "Miaou !" << std::endl;
}

void	Cat::put_idea(std::string idea, int index)
{
	this->_brain->setIdea(idea, index);
}

void	Cat::print_ideas(void) const
{
	std::cout << "All ideas :" << std::endl;
	for (int index = 0; index < 100; ++index) 
	{
		if (this->_brain->getIdea(index) != "")
			std::cout << "Idea " << index << ": " << this->_brain->getIdea(index) << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain*	Cat::getBrain(void) const
{
	return this->_brain;
}

/* ************************************************************************** */