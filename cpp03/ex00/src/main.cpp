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

void	attack_func( ClapTrap &invader, ClapTrap &victim)
{
	invader.attack(victim.getName());
	victim.takeDamage(invader.getAttackPoint());
}

int	main(void)
{
	ClapTrap	one("One");
	ClapTrap	another("Another");
	attack_func(one, another);

	one.setAttackPoint(10);

	attack_func(one, another);
    one.beRepaired(15);
	attack_func(another, one);
    one.beRepaired(2);
	attack_func(one, another);
    one.beRepaired(5);
	return (0);
}
