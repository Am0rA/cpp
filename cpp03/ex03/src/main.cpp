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

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

void	attack_func(ClapTrap &invader, ClapTrap &victim)
{
	invader.attack(victim.getName());
	victim.takeDamage(invader.getAttackPoint());
}

int main()
{
    ClapTrap ciguli("Ciguli");
    ClapTrap ajdar("Ajdar");

	attack_func(ciguli, ajdar);

    ScavTrap scooby("Scooby");
	attack_func(ciguli, scooby);

	ScavTrap scoobi = scooby;
	attack_func(scoobi, scooby);
	attack_func(ciguli, scoobi);
    scooby.guardGate();
    ciguli.beRepaired(35);
    scooby.beRepaired(80);

	attack_func(ciguli, scooby);
    ciguli.beRepaired(33);
	FragTrap frog("Frog");
	attack_func(frog, ciguli);
	frog.beRepaired(999);
	frog.highFivesGuys();
    DiamondTrap diamond;
    diamond.whoAmI();
    attack_func(diamond, ciguli);
    attack_func(frog, diamond);
    diamond.beRepaired(50);
    diamond.whoAmI();
    diamond.guardGate();
    diamond.highFivesGuys();
    return 0;
}
