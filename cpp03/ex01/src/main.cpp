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

void	attack_func( ClapTrap &invader, ClapTrap &victim)
{
	invader.attack(victim.getName());
	victim.takeDamage(invader.getAttackPoint());
}

int main()
{
    ClapTrap ciguli("Ciguli");
    ClapTrap ajdar("Ajdar");

	attack_func(ciguli, ajdar);

    ScavTrap scavTrap("Scavvy");
	attack_func(ciguli, scavTrap);

	ScavTrap scaviTrap = scavTrap;
	attack_func(ciguli, scaviTrap);
    scavTrap.guardGate();
    ciguli.beRepaired(35);
    scavTrap.beRepaired(80);

	attack_func(ciguli, scavTrap);
    ciguli.beRepaired(33);

    return 0;
}
