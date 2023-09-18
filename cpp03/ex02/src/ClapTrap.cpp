/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:07:45 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:07:45 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "default";
	_hp = 10;
	_ep = 10;
	_ap = 0;
	std::cout << YELLOW "Default Constructor of ClapTrap called" DEFCOLOR << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
    : _name(copy.getName()),
      _hp(copy.getHitPoint()),
      _ep(copy.getEnergyPoint()),
      _ap(copy.getAttackPoint())
{
    std::cout << YELLOW "Copy Constructor of ClapTrap called" DEFCOLOR << std::endl;
}
ClapTrap::ClapTrap(std::string _name, unsigned int p_hit, unsigned int p_energy, unsigned int p_attack)
{
	this->_name = _name;
	_hp = p_hit;
	_ep = p_energy;
	_ap = p_attack;
	std::cout << YELLOW "Fields Constructor of ClapTrap called" DEFCOLOR << std::endl;
}


ClapTrap::~ClapTrap()
{
	std::cout << PURP "Destructor of ClapTrap called" DEFCOLOR << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	_name = assign.getName();
	_hp = assign.getHitPoint();
	_ep = assign.getEnergyPoint();
	_ap = assign.getAttackPoint();
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

unsigned int ClapTrap::getHitPoint() const
{
	return _hp;
}
void ClapTrap::setHitPoint(unsigned int p_hit)
{
	_hp = p_hit;
}

unsigned int ClapTrap::getEnergyPoint() const
{
	return _ep;
}
void ClapTrap::setEnergyPoint(unsigned int p_energy)
{
	_ep = p_energy;
}

unsigned int ClapTrap::getAttackPoint() const
{
	return _ap;
}
void ClapTrap::setAttackPoint(unsigned int p_attack)
{
	_ap = p_attack;
}

void ClapTrap::attack(const std::string& target)
{
	if (target.empty())
	{
		std::cout << "I can't attack to void." << std::endl;
		return ;
	}
	else if (this->getEnergyPoint() == 0)
	{
		std::cout << BLUE << this->getName();
		std::cout << " has no Energy points" << std::endl;
		return ;
	}
	else if (this->getAttackPoint() == 0)
	{
		std::cout << BLUE << this->getName();
		std::cout << " has no Attack power" << std::endl;
		return ;
	}
	std::cout << BLUE << this->getName() << DEFCOLOR;
	std::cout << " attacks " << RED << target << DEFCOLOR;
	std::cout << ", causing " << GREEN << this->getAttackPoint() << DEFCOLOR;
	std::cout << " points of damage!";
	this->setEnergyPoint(this->getEnergyPoint() - 1);
	std::cout << "and has " << RED << this->getEnergyPoint() << DEFCOLOR << " energy point left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int newHitPoint;
	unsigned int tmp;

	tmp = this->getHitPoint() - amount;
	if (tmp > this->getHitPoint())
		newHitPoint = 0;
	else
		newHitPoint = tmp;
	std::cout << BLUE << this->getName() << DEFCOLOR << ": Ouch!";
	std::cout << " I received " << RED << amount << DEFCOLOR;
	std::cout << " damage!" << std::endl;
	this->setHitPoint(newHitPoint);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoint() == 0)
	{
		std::cout << BLUE << this->getName() << DEFCOLOR << " can't regenerate because has" RED " NO " DEFCOLOR "Energy points left." << std::endl;
		return ;
	}
	std::cout << BLUE << this->getName() << DEFCOLOR << " regenerates " << GREEN << amount << DEFCOLOR << " hit points and reaches ";
	this->setHitPoint(this->getHitPoint() + amount);
	std::cout << GREEN << this->getHitPoint() << DEFCOLOR << " points. ";;
	this->setEnergyPoint(this->getEnergyPoint() - 1);
	std::cout << this->getName() << " has " << RED << this->getEnergyPoint() << DEFCOLOR << " energy points left" << std::endl;
}
