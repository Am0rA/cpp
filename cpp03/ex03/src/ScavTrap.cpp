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

const std::string	ScavTrap::_c_name = "ScavTrap";
const unsigned int	ScavTrap::_c_hp = 100;
const unsigned int	ScavTrap::_c_ep = 50;
const unsigned int	ScavTrap::_c_ap = 20;

ScavTrap::ScavTrap() :
	ClapTrap(ScavTrap::_c_name)
{
    std::cout << YELLOW "Default ScavTrap Constructor called" DEFCOLOR << "\n";
    setHitPoint(ScavTrap::_c_hp);
    setEnergyPoint(ScavTrap::_c_ep);
    setAttackPoint(ScavTrap::_c_ap);
}

ScavTrap::ScavTrap(std::string name) :
	ClapTrap(name)
{
    std::cout << YELLOW "ScavTrap Constructor called" DEFCOLOR << "\n";
    setHitPoint(ScavTrap::_c_hp);
    setEnergyPoint(ScavTrap::_c_ep);
    setAttackPoint(ScavTrap::_c_ap);
}

ScavTrap::ScavTrap(const ScavTrap &copy) :
	ClapTrap(copy)
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

// Static getters
std::string ScavTrap::getClassName() 
{
    return _c_name;
}

unsigned int ScavTrap::getClassHitPoint() 
{
    return _c_hp;
}

unsigned int ScavTrap::getClassEnergyPoint() 
{
    return _c_ep;
}

unsigned int ScavTrap::getClassAttackPoint() 
{
    return _c_ap;
}

// Member functions
void ScavTrap::guardGate()
{
    std::cout << YELLOW << getName() << DEFCOLOR << " is now in Gate keeper mode." << "\n";
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << YELLOW << getName() << DEFCOLOR << " (ScavTrap) attacks " RED << target << DEFCOLOR ", causing " << getAttackPoint() << " points of damage!" << "\n";
}
