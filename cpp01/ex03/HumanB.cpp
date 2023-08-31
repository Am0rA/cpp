/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:02:31 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:02:31 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " is unarmed" << std::endl;
}

void	HumanB::setWeapon(Weapon &type)
{
	this->_weapon = &type;
}

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB(){}