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
	this->setPhit(100);
	this->setPenergy(100);
	this->setPattack(30);
	std::cout << YELLOW "Default Constructor of FragTrap called" DEFCOLOR << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	this->setName(name);
	this->setPhit(100);
	this->setPenergy(100);
	this->setPattack(30);
}

FragTrap::FragTrap(const FragTrap &copy)
    : ClapTrap(copy.getName(), copy.getPhit(), copy.getPenergy(), copy.getPattack())
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
	this->setPattack(assign.getPattack());
	this->setPenergy(assign.getPenergy());
	this->setPhit(assign.getPhit());
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "HEeYEyY HighFive" << std::endl;
}

