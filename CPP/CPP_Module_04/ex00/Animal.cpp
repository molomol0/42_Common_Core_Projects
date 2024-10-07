#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(): _type("Default_type")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(Animal & src )
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal Default Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	this->_type = rhs._type;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const &i )
{
	o << "Type = " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound() const 
{
    // std::cout << "Animal makes a generic sound" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Animal::getType(void) const
{
	return this->_type;
}

void		Animal::setType(std::string type)
{
	if (type == "Dog" || type == "Cat")
		this->_type = type;
}

/* ************************************************************************** */