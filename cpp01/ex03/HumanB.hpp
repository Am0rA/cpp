/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:02:41 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:02:41 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
	public:
		HumanB(std::string _name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &type);
	private:
		std::string _name;
		Weapon	*_weapon;
};

#endif