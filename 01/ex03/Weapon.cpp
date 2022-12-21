#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "Called default weapon constructor\n";
}

Weapon::~Weapon(void)
{
	std::cout << "Called default weapon destructor\n";
}

const std::string &Weapon::getType(void)
{
	return this->type;
}

std::string Weapon::setType(std::string type)
{
	this->type = type;
	return this->type;
}
