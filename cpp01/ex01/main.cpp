/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:00:37 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:00:37 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Horde;
	int		size = 50;

	Horde = zombieHorde(size, "Golden");
	for (int i = 0; i < size; i++)
	{
		std::cout << "num: " << i << " ";
		Horde[i].announce();
	}
	delete [] Horde;
	return (0);
}