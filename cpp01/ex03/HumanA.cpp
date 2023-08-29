#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

// HumanA::HumanA(std::string name, Weapon &weapon)
// {
//     this->_name = name;
//     this->_weapon = weapon;
// }

HumanA::HumanA(std::string name, Weapon &Weapon) : _name(name),  _weapon(Weapon){}

HumanA::~HumanA(){}
