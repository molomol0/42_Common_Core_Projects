#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &		operator=( Brain const & rhs );

		std::string getIdea(int index) const;
		void		setIdea(std::string, int index);

	private:

		std::string *_ideas;

};

#endif /* *********************************************************** BRAIN_H */