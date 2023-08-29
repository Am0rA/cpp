#include "Harl.hpp"

int	main(int ac, char **av)
{
	std::string input;
	Harl	harl;

	if (ac != 2)
	{
		std::cout << "Usage: " << RED << "./Harl type" << WHITE << std::endl;
		return (1);
	}
	input = av[1];
	harl.complain(input);
	return (0);
}
