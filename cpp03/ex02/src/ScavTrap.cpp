/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 21:40:38 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 21:40:38 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

const std::string ScavTrap::DEFAULT_NAME = "ScavTrap";

ScavTrap::ScavTrap() :
	ClapTrap(DEFAULT_NAME)
{
	std::cout << YELLOW "A ScavTrap called " << ScavTrap::DEFAULT_NAME << " is constructed" DEFCOLOR << std::endl;
    setHitPoint(DEFAULT_HP);
    setEnergyPoint(DEFAULT_EP);
    setAttackPoint(DEFAULT_AP);
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << YELLOW "A ScavTrap called " << _name << " is constructed" DEFCOLOR << std::endl;
    setHitPoint(DEFAULT_HP);
    setEnergyPoint(DEFAULT_EP);
    setAttackPoint(DEFAULT_AP);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << YELLOW "A copy ScavTrap of " << copy.getName() << " is constructed" DEFCOLOR << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << PURP "A ScavTrap called " << this->getName() << " is deconstructed" DEFCOLOR << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
    setName(assign.getName());
    setHitPoint(assign.getHitPoint());
    setEnergyPoint(assign.getEnergyPoint());
    setAttackPoint(assign.getAttackPoint());
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << YELLOW << getName() << DEFCOLOR << " is now in Gate keeper mode." << "\n";
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << YELLOW << getName() << DEFCOLOR << " (ScavTrap) attacks " RED << target << DEFCOLOR ", causing " << getAttackPoint() << " points of damage!" << "\n";
}
