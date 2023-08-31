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

int	main(void)
{
	ClapTrap	victim("Victim", 100, 2, 9);
	ClapTrap	invader("Invader", 100, 40, 8);
	invader.attack("Victim");
    victim.takeDamage(invader.getP_attack());
    invader.attack("Victim");
    victim.takeDamage(invader.getP_attack());
    victim.beRepaired(35);
    victim.beRepaired(80);
    victim.takeDamage(invader.getP_attack());
    victim.beRepaired(33);
	return (0);
}