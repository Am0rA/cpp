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

const std::string	DiamondTrap::_c_name = "DiamondTrap";

DiamondTrap::DiamondTrap() :
	ClapTrap("diamond_clap_trap"),
    FragTrap("diamond_frag_trap"),
	ScavTrap("diamond_scav_trap")
{
    std::cout << YELLOW "A DiamondTrap called " BLUE "DiamondTrap" YELLOW " is born!\n" DEFCOLOR;
	this->_name = getClassName();
	this->setAttackPoint(FragTrap::getClassAttackPoint());
	this->setEnergyPoint(ScavTrap::getClassEnergyPoint());
	this->setHitPoint(FragTrap::getClassHitPoint());
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_trap"),
    FragTrap(name + "_frag_trap"),
	ScavTrap(name + "_scav_trap")
{
    std::cout << YELLOW "A DiamondTrap called " BLUE << name << YELLOW " is born!\n" DEFCOLOR;
    this->_name = name;
	this->setAttackPoint(FragTrap::getClassAttackPoint());
	this->setEnergyPoint(ScavTrap::getClassEnergyPoint());
	this->setHitPoint(FragTrap::getClassHitPoint());
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) :
	ClapTrap(copy._name + "_clap_trap"),
    FragTrap(copy._name + "_frag_trap"), 
	ScavTrap(copy._name + "_scav_trap")
{
	std::cout << YELLOW "Copy constructor of DiamondTrap is called and " << copy.getClassName() << " is copied\n" DEFCOLOR;
    *this = copy;
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

// Static getters
std::string DiamondTrap::getClassName() 
{
    return (_c_name);
}

unsigned int DiamondTrap::getClassHitPoint() 
{
    return (DiamondTrap::getClassHitPoint());
}

unsigned int DiamondTrap::getClassEnergyPoint() 
{
	return (ScavTrap::getClassEnergyPoint());
}

unsigned int DiamondTrap::getClassAttackPoint() 
{	
	return (DiamondTrap::getClassAttackPoint());
}

// Member functions
void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap's name is " << BLUE << this->_name << DEFCOLOR << std::endl;
    std::cout << "ClapTrap's name is " << BLUE << ClapTrap::getName() << DEFCOLOR << std::endl;
}
