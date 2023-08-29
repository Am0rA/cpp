#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	public:
		HumanA(std::string name, Weapon &Weapon);
		~HumanA();
		void attack();
	private:
		std::string _name;
		Weapon	&_weapon;
};

#endif