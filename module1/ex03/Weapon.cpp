#include "Weapon.hpp"

Weapon::Weapon(void) {
    std::cout << "Called default constructor of Weapon" << std::endl;
}

Weapon::Weapon(const std::string type) {
    this->type = type;
}

Weapon::~Weapon(void) {
    std::cout << "Called default destructor of Weapon" << std::endl;
}

const std::string &Weapon::getType(void) {
    return this->type;
}

void Weapon::setType(const std::string type) {
    this->type = type;
}
