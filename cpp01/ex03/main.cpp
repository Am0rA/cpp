/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:02:48 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:02:48 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon club1 = Weapon("crude spiked club");
	HumanA bob("Bob", club1);
	bob.attack();
	club1.setType("Pikachu");
	bob.attack();
	Weapon club2 = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("None");
	jim.attack();
	return (0);
}
