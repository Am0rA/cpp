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
	_p_hit = copy.getP_hit();
	_p_energy = copy.getP_energy();
	_p_attack = copy.getP_attack();
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
	_p_hit = assign.getP_hit();
	_p_energy = assign.getP_energy();
	_p_attack = assign.getP_attack();
	return *this;
}


std::string ClapTrap::getName() const
{
	return _name;
}
void ClapTrap::set_name(std::string _name)
{
	this->_name = _name;
}

unsigned int ClapTrap::getP_hit() const
{
	return _p_hit;
}
void ClapTrap::setP_hit(unsigned int p_hit)
{
	_p_hit = p_hit;
}

unsigned int ClapTrap::getP_energy() const
{
	return _p_energy;
}
void ClapTrap::setP_energy(unsigned int p_energy)
{
	_p_energy = p_energy;
}

unsigned int ClapTrap::getP_attack() const
{
	return _p_attack;
}
void ClapTrap::setP_attack(unsigned int p_attack)
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
	else if (this->getP_energy() == 0)
	{
		std::cout << BLUE << this->getName();
		std::cout << " has no Energy points" << std::endl;
		return ;
	}
	else if (this->getP_attack() == 0)
	{
		std::cout << BLUE << this->getName();
		std::cout << " has no Attack power" << std::endl;
		return ;
	}
	std::cout << BLUE << this->getName() << DEFCOLOR;
	std::cout << " attacks " << RED << target << DEFCOLOR;
	std::cout << ", causing " << GREEN << this->getP_attack() << DEFCOLOR;
	std::cout << " points of damage!";
	this->setP_energy(this->getP_energy() - 1);
	std::cout << "and has " << RED << this->getP_energy() << DEFCOLOR << " energy point left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int newHitPoint;
	unsigned int tmp;

	tmp = this->getP_hit() - amount;
	if (tmp > this->getP_hit())
		newHitPoint = 0;
	else
		newHitPoint = this->getP_hit() - amount;
	std::cout << BLUE << this->getName() << DEFCOLOR << ": Ouch!";
	std::cout << " I received " << RED << amount << DEFCOLOR;
	std::cout << " damage!" << std::endl;
	this->setP_hit(newHitPoint);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getP_energy() == 0)
	{
		std::cout << BLUE << this->getName() << DEFCOLOR << " can't regenerate because has" RED " NO " DEFCOLOR "Energy points left." << std::endl;
		return ;
	}
	std::cout << BLUE << this->getName() << DEFCOLOR << " regenerates " << GREEN << amount << DEFCOLOR << " hit points and reaches ";
	this->setP_hit(this->getP_hit() + amount);
	std::cout << GREEN << this->getP_hit() << DEFCOLOR << " points. ";;
	this->setP_energy(this->getP_energy() - 1);
	std::cout << this->getName() << " has " << RED << this->getP_energy() << DEFCOLOR << " energy points left" << std::endl;
}
