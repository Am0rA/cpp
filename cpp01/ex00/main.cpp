/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 12:56:06 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 12:56:06 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombie;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Zombie = newZombie("Choko");
	Zombie->announce();
	randomChump("Chump");
	randomChump("");
	delete (Zombie);
	return (0);
}