/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:08:00 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:08:00 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	attack_func(ClapTrap &victim, ClapTrap &invader)
{
	invader.attack(victim.getName());
	victim.takeDamage(invader.getAttackPoint());
}

int main()
{
    ClapTrap victim("Victim");
    ClapTrap invader("Invader");

	attack_func(victim, invader);

    ScavTrap scavTrap("Scavvy");
	attack_func(victim, scavTrap);

	ScavTrap scaviTrap = scavTrap;
	attack_func(victim, scaviTrap);
    scavTrap.guardGate();
    victim.beRepaired(35);
    scavTrap.beRepaired(80);

	attack_func(victim, invader);
    victim.beRepaired(33);

    return 0;
}
