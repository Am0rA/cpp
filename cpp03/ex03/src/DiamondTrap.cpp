/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 01:23:32 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/06 01:23:32 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name + "_clap_trap"), FragTrap(name + "_clap_trap")
{
	this->_name = name;
	std::cout << "A DiamondTrap called " << name << " is born!\n";
}

DiamondTrap::DiamondTrap(DiamondTrap const & ref) : ClapTrap(ref.get_name()), ScavTrap(ref.get_name() + "_scav_trap"), FragTrap(ref.get_name() + "_clap_trap")
{
	this->_name = ref.get_name();
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " is a coal now...\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	this->_name = other.get_name();
	return (*this);
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap's name is " << BLUE << this->_name << DEFCOLOR << std::endl;
	std::cout << "ClapTrap's name is " << BLUE << this->get_name() << DEFCOLOR << std::endl;
}