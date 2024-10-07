#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->setType("Dog");
}

Dog::Dog( const Dog & src )
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog Default Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &			Dog::operator=( Dog const & rhs )
{
	this->_type = rhs.getType();
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, Dog const & i )
// {
// 	o << "Type = " << i.getType();
// 	return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound(void) const
{
	std::cout << "Waf !" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */