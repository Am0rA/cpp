/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:02:56 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:02:56 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
}

// Destructor
Weapon::~Weapon()
{

}

// Getters / Setters
std::string Weapon::getType() const
{
	return _type;
}
void Weapon::setType(std::string type)
{
	_type = type;
}

