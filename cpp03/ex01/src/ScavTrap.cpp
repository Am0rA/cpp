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

ScavTrap::ScavTrap() : ClapTrap("Scav", 100, 50, 20)
{
    std::cout << YELLOW "Default ScavTrap Constructor called" DEFCOLOR << "\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << YELLOW "ScavTrap Constructor called" DEFCOLOR << "\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << PURP "ScavTrap Destructor called" DEFCOLOR << "\n";
}

void ScavTrap::guardGate()
{
    std::cout << YELLOW << getName() << DEFCOLOR << " is now in Gate keeper mode." << "\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy)
    : ClapTrap(copy.getName(), copy.getPhit(), copy.getPenergy(), copy.getPattack())
{
    std::cout << YELLOW "ScavTrap Copy Constructor called" DEFCOLOR << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	this->setName(assign.getName());
	this->setPhit(assign.getPhit());
	this->setPattack(assign.getPenergy());
	this->setPenergy(assign.getPattack());
	return *this;
}

