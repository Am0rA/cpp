#include "HumanB.hpp"

void	HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " is unarmed" << std::endl;
}

void	HumanB::setWeapon(Weapon &type)
{
	this->_weapon = &type;
}

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB(){}