#include <iostream>
#include <string>
#include <cctype>

void	writeToUpperCase(char *s)
{
	int	i = -1;
	while (s[++i])
	{
		if (isalpha(s[i]))
			toupper(s[i]);
		std::cout << s[i];
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
	else
	{
		std::string	message = "";
		for(int i = 1; i < ac; i++)
		{
			writeToUpperCase(av[i]);
			if (i != ac - 1)
				std::cout << " ";
		}
		std::cout << "\n";
	}
	return (0);
}
