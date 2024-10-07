#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "hard early mid need gank" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Zed perma push I need help" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "no flash mid" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "x9 jungle" << std::endl;
}

void	Harl::complain(std::string level)
{
	int		index;
	void	(Harl::*fct[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (lvl[i] == level)
			index = i;
	}
	switch (index) {
		case 1:
			for (int i = 1; i < 4; i++)
			{
				(this->*(fct[i]))();
				std::cout << std::endl;
			}
			break;
		case 2:
			for (int i = 2; i < 4; i++)
			{
				(this->*(fct[i]))();
				std::cout << std::endl;
			}
			break;
		case 3:
			for (int i = 3; i < 4; i++)
			{
				(this->*(fct[i]))();
				std::cout << std::endl;
			}
			break;
		case 4:
			for (int i = 4; i < 4; i++)
			{
				(this->*(fct[i]))();
				std::cout << std::endl;
			}
			break;
	}
}