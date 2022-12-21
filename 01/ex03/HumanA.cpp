#include "HumanA.hpp"

HumanA::HumanA(std::string const &name, Weapon &weapon)
{
	std::cout << "Deafault constructor of HumanA called\n";
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA(void)
{
	std::cout << "Default destructor of HumanA called\n";
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << '\n';
}
