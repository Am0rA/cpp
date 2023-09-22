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

const std::string DiamondTrap::DEFAULT_NAME = "DiamondTrap";

DiamondTrap::DiamondTrap() :
	ClapTrap("diamond_clap_trap"),
    FragTrap("diamond_frag_trap"),
	ScavTrap("diamond_scav_trap")
{
	std::cout << YELLOW "A DiamondTrap called " << DiamondTrap::DEFAULT_NAME << " is constructed" DEFCOLOR << std::endl;
	this->setName(DiamondTrap::DEFAULT_NAME);
	this->setAttackPoint(DiamondTrap::DEFAULT_AP);
	this->setEnergyPoint(DiamondTrap::DEFAULT_EP);
	this->setHitPoint(DiamondTrap::DEFAULT_HP);
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_trap"),
    FragTrap(name + "_frag_trap"),
	ScavTrap(name + "_scav_trap")
{
	std::cout << YELLOW "A DiamondTrap called " << _name << " is constructed" DEFCOLOR << std::endl;
    this->_name = name;
	this->setAttackPoint(DiamondTrap::DEFAULT_AP);
	this->setEnergyPoint(DiamondTrap::DEFAULT_EP);
	this->setHitPoint(DiamondTrap::DEFAULT_HP);
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) :
	ClapTrap(copy._name + "_clap_trap"),
    FragTrap(copy._name + "_frag_trap"), 
	ScavTrap(copy._name + "_scav_trap")
{
    std::cout << YELLOW "A copy DiamondTrap of " << copy.getName() << " is constructed" DEFCOLOR << std::endl;
    *this = copy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << PURP "A DiamondTrap called " << this->getName() << " is deconstructed" DEFCOLOR << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
    this->_name = other._name;
	this->setAttackPoint(other.getAttackPoint());
	this->setEnergyPoint(other.getEnergyPoint());
	this->setHitPoint(other.getHitPoint());
    return (*this);
}

// Member functions
void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap's name is " << BLUE << this->_name << DEFCOLOR << std::endl;
    std::cout << "ClapTrap's name is " << BLUE << ClapTrap::getName() << DEFCOLOR << std::endl;
}
