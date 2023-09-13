/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 12:59:52 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 12:59:52 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie newZombie;

	if (name.empty())
		newZombie.setRandomName();
	else
		newZombie.setName(name);
	newZombie.announce();
}
