#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	karen;

	if (argc < 2)
	{
		std::cout << "Please enter a filter level" << std::endl;
		return (-1);
	}
	if (argc > 2)
	{
		std::cout << "Too many arguments" << std::endl;
		return (-1);
	}
	karen.complain(argv[1]);
}