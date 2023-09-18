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

const std::string	ClapTrap::_c_name = "ClapTrap";
const unsigned int	ClapTrap::_c_hp = 10;
const unsigned int	ClapTrap::_c_ep = 10;
const unsigned int	ClapTrap::_c_ap = 0;

// Form

ClapTrap::ClapTrap() : \
	_name(ClapTrap::_c_name), \
	_hp(ClapTrap::_c_hp), \
	_ep(ClapTrap::_c_ep), \
	_ap(ClapTrap::_c_ap)
{
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

ClapTrap::ClapTrap(std::string _name) : \
	_name(_name), \
	_hp(getClassHitPoint()), \
	_ep(getClassEnergyPoint()), \
	_ap(getClassAttackPoint())
{
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

// getters
std::string ClapTrap::getName() const
{
	return this->_name;
}
unsigned int ClapTrap::getHitPoint() const
{
	return this->_hp;
}
unsigned int ClapTrap::getEnergyPoint() const
{
	return this->_ep;
}
unsigned int ClapTrap::getAttackPoint() const
{
	return this->_ap;
}

//Setters
void ClapTrap::setName(std::string _name)
{
	this->_name = _name;
}
void ClapTrap::setHitPoint(unsigned int hit_p)
{
	this->_hp = hit_p;
}
void ClapTrap::setEnergyPoint(unsigned int energy_p)
{
	this->_ep = energy_p;
}
void ClapTrap::setAttackPoint(unsigned int attack_p)
{
	this->_ap = attack_p;
}

// Static getters
std::string ClapTrap::getClassName() 
{
    return _c_name;
}

unsigned int ClapTrap::getClassHitPoint() 
{
    return _c_hp;
}

unsigned int ClapTrap::getClassEnergyPoint() 
{
    return _c_ep;
}

unsigned int ClapTrap::getClassAttackPoint() 
{
    return _c_ap;
}

// member functions
void ClapTrap::attack(const std::string& target)
{
	if (this->getHitPoint() == 0)
	{
		std::cout << RED << "(" << this->getName() << DEFCOLOR << ") Deads were attacking in cpp01!" << DEFCOLOR << std::endl;
		return ;
	}
	else if (this->getEnergyPoint() == 0)
	{
		std::cout << BLUE << this->getName() << DEFCOLOR;
		std::cout << " has no Energy points" << std::endl;
		return ;
	}
	else if (target.empty())
	{
		std::cout << this->getName() << ": I can't attack to void." << std::endl;
		return ;
	}
	else if (this->getAttackPoint() == 0)
	{
		std::cout << BLUE << this->getName() << DEFCOLOR;
		std::cout << " has no Attack power" << std::endl;
		return ;
	}
	std::cout << BLUE << this->getName() << DEFCOLOR;
	std::cout << " attacks " << RED << target << DEFCOLOR;
	std::cout << ", causing " << GREEN << this->getAttackPoint() << DEFCOLOR;
	std::cout << " points of damage!";
	this->setEnergyPoint(this->getEnergyPoint() - 1);
	std::cout << " And has " << RED << this->getEnergyPoint() << DEFCOLOR << " energy point left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int newHitPoint;
	unsigned int tmp;

	if (this->getHitPoint() == 0)
	{
		std::cout << RED << "(" << this->getName() << ") I am already dead you monster!" << DEFCOLOR << std::endl;
		return ;
	}
	else if (amount == 0)
	{
		std::cout << "Such a useless attempt\n";
		return ;
	}
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
	if (this->getHitPoint() == 0)
	{
		std::cout << RED << "(" << this->getName() << ") I am dead!" << DEFCOLOR << std::endl;
		return ;
	}
	else if (this->getEnergyPoint() == 0)
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
