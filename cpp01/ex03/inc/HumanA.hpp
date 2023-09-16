/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:02:20 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:02:20 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	public:
		HumanA(std::string name, Weapon &Weapon);
		~HumanA();
		void attack();
	private:
		std::string _name;
		Weapon	&_weapon;
};

#endif