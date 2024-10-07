#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default Constructor called" << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat( const WrongCat & src )
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Default Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &			WrongCat::operator=( WrongCat const & rhs )
{
	this->_type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongCat::makeSound(void) const
{
	std::cout << "! uoaiM" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */