/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:05:54 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:05:54 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	std::string input;
	Harl	harl;

	if (ac != 2)
	{
		std::cout << "Usage: " << RED << "./harl type" << WHITE << std::endl;
		return (1);
	}
	input = av[1];
	harl.complain(input);
	return (0);
}
