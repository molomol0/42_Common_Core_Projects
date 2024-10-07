#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog( const Dog & src )
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->_type = src.getType();
	this->_brain = new Brain(*(src.getBrain()));
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog Default Destructor called" << std::endl;
	if (this->_brain)
		delete(this->_brain);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &			Dog::operator=( Dog const & rhs )
{
	this->_type = rhs.getType();
	this->_brain = rhs.getBrain();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound(void) const
{
	std::cout << "Waf !" << std::endl;
}

void	Dog::put_idea(std::string idea, int index)
{
	this->_brain->setIdea(idea, index);
}

void	Dog::print_ideas(void) const
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

Brain*	Dog::getBrain(void) const
{
	return this->_brain;
}

/* ************************************************************************** */