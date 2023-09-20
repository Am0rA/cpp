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

DiamondTrap::DiamondTrap() :
	ClapTrap("diamond_clap_trap"),
    FragTrap(),
	ScavTrap()
{
    std::cout << YELLOW "A DiamondTrap called " BLUE "DiamondTrap" YELLOW " is born!\n" DEFCOLOR;
	this->_name = "DiamondTrap";
	this->setAttackPoint(FragTrap::getClassAttackPoint());
	this->setEnergyPoint(ScavTrap::getClassEnergyPoint());
	this->setHitPoint(FragTrap::getClassHitPoint());
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_trap"),
    FragTrap(),
	ScavTrap()
{
    std::cout << YELLOW "A DiamondTrap called " BLUE << name << YELLOW " is born!\n" DEFCOLOR;
    this->_name = name;
	this->setAttackPoint(FragTrap::getClassAttackPoint());
	this->setEnergyPoint(ScavTrap::getClassEnergyPoint());
	this->setHitPoint(FragTrap::getClassHitPoint());
}

DiamondTrap::DiamondTrap(DiamondTrap const & ref) :
	ClapTrap(ref._name + "_clap_trap"),
    FragTrap(), 
	ScavTrap()
{
	std::cout << YELLOW "Copy constructor of DiamondTrap is called and " << ref.getClassName() << " is copied\n" DEFCOLOR;
    *this = ref;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << PURP "DiamondTrap " << this->_name << " is a coal now...\n" DEFCOLOR;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
    this->_name = other._name;
	this->setAttackPoint(other.getAttackPoint());
	this->setEnergyPoint(other.getEnergyPoint());
	this->setHitPoint(other.getHitPoint());
    return (*this);
}

void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap's name is " << BLUE << this->_name << DEFCOLOR << std::endl;
    std::cout << "ClapTrap's name is " << BLUE << FragTrap::getName() << DEFCOLOR << std::endl;
}