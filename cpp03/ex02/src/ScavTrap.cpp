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

ScavTrap::ScavTrap() : ClapTrap("Scav")
{
    std::cout << YELLOW "Default ScavTrap Constructor called" DEFCOLOR << "\n";
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackPoint(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << YELLOW "ScavTrap Constructor called" DEFCOLOR << "\n";
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackPoint(20);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << YELLOW "ScavTrap Copy Constructor called" DEFCOLOR << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap()
{
    std::cout << PURP "ScavTrap Destructor called" DEFCOLOR << "\n";
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
