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

int main()
{
    ClapTrap victim("Victim", 100, 2, 9);
    ClapTrap invader("Invader", 100, 40, 8);

    invader.attack("Victim");
    victim.takeDamage(invader.getPattack());

    ScavTrap scavTrap("Scavvy");
    scavTrap.attack("Victim");
    victim.takeDamage(scavTrap.getPattack());

	ScavTrap scaviTrap = scavTrap;
	invader.attack(scavTrap.getName());
	scavTrap.takeDamage(invader.getPattack());
    scavTrap.guardGate();

    victim.beRepaired(35);
    scavTrap.beRepaired(80);

    invader.attack("Victim");
    victim.takeDamage(invader.getPattack());

    victim.beRepaired(33);

    return 0;
}
