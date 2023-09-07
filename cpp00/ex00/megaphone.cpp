/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 12:53:42 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 12:53:42 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	toUpperCase(char *s)
{
	int	i = -1;
	while (s[++i])
	{
		if (isalpha(s[i]))
			s[i] = toupper(s[i]);
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
	else
	{
		for(int i = 1; i < ac; i++)
		{
			toUpperCase(av[i]);
			std::cout << av[i];
		}
		std::cout << "\n";
	}
	return (0);
}
