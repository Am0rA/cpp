/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:00:57 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:00:57 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*Horde = NULL;
	if (N <= 0)
		return (Horde);
	Horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		Horde[i].setName(name);
	return (Horde);
}