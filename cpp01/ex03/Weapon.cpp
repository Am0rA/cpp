#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
}

// Destructor
Weapon::~Weapon()
{

}

// Getters / Setters
std::string Weapon::getType() const
{
	return _type;
}
void Weapon::setType(std::string type)
{
	_type = type;
}

