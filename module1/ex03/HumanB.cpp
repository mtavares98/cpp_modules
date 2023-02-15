#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) {
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB(void) {
    std::cout << "Called default destructor of Human B" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void HumanB::attack(void) {
    std::cout << this->name << " attacks with their ";
    if (this->weapon)
        std::cout << this->weapon->getType() << std::endl;
    else
        std::cout << "is attacking with bare hands" << std::endl;
}
