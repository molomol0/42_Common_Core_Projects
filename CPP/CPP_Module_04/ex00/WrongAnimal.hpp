#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:

		WrongAnimal();
		WrongAnimal(WrongAnimal &WrongAnimal);
		~WrongAnimal();

		WrongAnimal			&operator=(const WrongAnimal &WrongAnimal);

		std::string		getType() const;
		void			setType(std::string type);

		virtual void	makeSound() const;

	protected:

		std::string _type;
};

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i );

#endif