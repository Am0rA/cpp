/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:07:11 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:07:11 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "default";
	_p_hit = 10;
	_p_energy = 10;
	_p_attack = 0;
	std::cout << YELLOW "Default Constructor of ClapTrap called" DEFCOLOR << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	_name = copy.getName();
	_p_hit = copy.getPhit();
	_p_energy = copy.getPenergy();
	_p_attack = copy.getPattack();
	std::cout << YELLOW "Copy Constructor of ClapTrap called" DEFCOLOR << std::endl;
}

ClapTrap::ClapTrap(std::string _name, unsigned int p_hit, unsigned int p_energy, unsigned int p_attack)
{
	this->_name = _name;
	_p_hit = p_hit;
	_p_energy = p_energy;
	_p_attack = p_attack;
	std::cout << YELLOW "Fields Constructor of ClapTrap called" DEFCOLOR << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << PURP "Destructor of ClapTrap called" DEFCOLOR << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	_name = assign.getName();
	_p_hit = assign.getPhit();
	_p_energy = assign.getPenergy();
	_p_attack = assign.getPattack();
	return *this;
}


std::string ClapTrap::getName() const
{
	return _name;
}
void ClapTrap::setName(std::string _name)
{
	this->_name = _name;
}

unsigned int ClapTrap::getPhit() const
{
	return _p_hit;
}
void ClapTrap::setPhit(unsigned int p_hit)
{
	_p_hit = p_hit;
}

unsigned int ClapTrap::getPenergy() const
{
	return _p_energy;
}
void ClapTrap::setPenergy(unsigned int p_energy)
{
	_p_energy = p_energy;
}

unsigned int ClapTrap::getPattack() const
{
	return _p_attack;
}
void ClapTrap::setPattack(unsigned int p_attack)
{
	_p_attack = p_attack;
}

void ClapTrap::attack(const std::string& target)
{
	if (target.empty())
	{
		std::cout << "I can't attack to void." << std::endl;
		return ;
	}
	else if (this->getPenergy() == 0)
	{
		std::cout << BLUE << this->getName();
		std::cout << " has no Energy points" << std::endl;
		return ;
	}
	else if (this->getPattack() == 0)
	{
		std::cout << BLUE << this->getName();
		std::cout << " has no Attack power" << std::endl;
		return ;
	}
	std::cout << BLUE << this->getName() << DEFCOLOR;
	std::cout << " attacks " << RED << target << DEFCOLOR;
	std::cout << ", causing " << GREEN << this->getPattack() << DEFCOLOR;
	std::cout << " points of damage!";
	this->setPenergy(this->getPenergy() - 1);
	std::cout << "and has " << RED << this->getPenergy() << DEFCOLOR << " energy point left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int newHitPoint;
	unsigned int tmp;

	tmp = this->getPhit() - amount;
	if (tmp > this->getPhit())
		newHitPoint = 0;
	else
		newHitPoint = this->getPhit() - amount;
	std::cout << BLUE << this->getName() << DEFCOLOR << ": Ouch!";
	std::cout << " I received " << RED << amount << DEFCOLOR;
	std::cout << " damage!" << std::endl;
	this->setPhit(newHitPoint);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getPenergy() == 0)
	{
		std::cout << BLUE << this->getName() << DEFCOLOR << " can't regenerate because has" RED " NO " DEFCOLOR "Energy points left." << std::endl;
		return ;
	}
	std::cout << BLUE << this->getName() << DEFCOLOR << " regenerates " << GREEN << amount << DEFCOLOR << " hit points and reaches ";
	this->setPhit(this->getPhit() + amount);
	std::cout << GREEN << this->getPhit() << DEFCOLOR << " points. ";;
	this->setPenergy(this->getPenergy() - 1);
	std::cout << this->getName() << " has " << RED << this->getPenergy() << DEFCOLOR << " energy points left" << std::endl;
}
