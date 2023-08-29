#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string	message = "";
		for(int i = 1; i < ac; i++)
		{
			message.append(av[i]);
			if (i != ac - 1)
				message.append(" ");
		}
		std::transform(message.begin(), message.end(), message.begin(), toupper);
		std::cout << message << std::endl;
	}
	return (0);
}
