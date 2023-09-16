/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:07:22 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:07:22 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	attack_func(ClapTrap &victim, ClapTrap &invader)
{
	invader.attack(victim.getName());
	victim.takeDamage(invader.getPattack());
}

int	main(void)
{
	ClapTrap	one("One", 100, 2, 9);
	ClapTrap	another("Another", 100, 40, 8);
	attack_func(one, another);
	attack_func(one, another);
    one.beRepaired(15);
	attack_func(another, one);
    one.beRepaired(2);
	attack_func(one, another);
    one.beRepaired(5);
	return (0);
}
