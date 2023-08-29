#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
	public:
		HumanB(std::string _name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &type);
	private:
		std::string _name;
		Weapon	*_weapon;
};

#endif