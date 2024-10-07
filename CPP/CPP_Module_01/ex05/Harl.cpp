#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "DEBUG : " << std::endl;
	std::cout << "hard early mid need gank" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO : " << std::endl;
	std::cout << "Zed perma push I need help" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING : " << std::endl;
	std::cout << "no flash mid" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR : " << std::endl;
	std::cout << "x9 jungle" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*fct[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	lvl[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
	{
		if (lvl[i] == level)
			(this->*(fct[i]))();
	}
}