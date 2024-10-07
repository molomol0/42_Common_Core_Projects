#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal(): _type("Wrong_default_type")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal & src )
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Default Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	this->_type = rhs._type;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongAnimal const &i )
{
	o << "Type = " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound() const 
{
    // std::cout << "WrongAnimal makes a generic sound" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	WrongAnimal::getType(void) const
{
	return this->_type;
}

void		WrongAnimal::setType(std::string type)
{
	if (type == "WrongCat")
		this->_type = type;
}

/* ************************************************************************** */