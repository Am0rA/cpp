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
    victim.takeDamage(invader.getP_attack());

    ScavTrap scavTrap("Scavvy");
    scavTrap.attack("Victim");
    victim.takeDamage(scavTrap.getP_attack());

	invader.attack(scavTrap.getName());
	scavTrap.takeDamage(invader.getP_attack());
    scavTrap.guardGate();

    victim.beRepaired(35);
    scavTrap.beRepaired(80);

    invader.attack("Victim");
    victim.takeDamage(invader.getP_attack());

    victim.beRepaired(33);

    return 0;
}
