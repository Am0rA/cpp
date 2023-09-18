/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/04 23:38:09 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/04 23:38:09 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->setName("FragTrap");
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackPoint(30);
	std::cout << YELLOW "Default Constructor of FragTrap called" DEFCOLOR << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	this->setName(name);
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackPoint(30);
}

FragTrap::FragTrap(const FragTrap &copy)
    : ClapTrap(copy.getName(), copy.getHitPoint(), copy.getEnergyPoint(), copy.getAttackPoint())
{
	std::cout << YELLOW "Copy Constructor of FragTrap called" DEFCOLOR << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << PURP "Destructor of FragTrap called" DEFCOLOR << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	this->setName(assign.getName());
	this->setAttackPoint(assign.getAttackPoint());
	this->setEnergyPoint(assign.getEnergyPoint());
	this->setHitPoint(assign.getHitPoint());
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "HEeYEyY HighFive" << std::endl;
}

