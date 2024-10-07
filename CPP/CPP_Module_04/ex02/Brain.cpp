#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Brain Default Constructor" << std::endl;
	this->_ideas = new std::string[100];
}

Brain::Brain( const Brain & src )
{
	std::cout << "Brain Copy Constructor" << std::endl;
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src.getIdea(i);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{	
	std::cout << "Brain Default Destructor" << std::endl;
	if (this->_ideas)
		delete [] this->_ideas;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return NULL;
	return (this->_ideas[index]);
}

void		Brain::setIdea(std::string idea, int index)
{
	if (index < 0 || index >= 100)
		return ;
	this->_ideas[index] = idea;
}

/* ************************************************************************** */