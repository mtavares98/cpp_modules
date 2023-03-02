#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
    std::cout << "Called default constructor of WrongAnimal" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const& copy) {
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& copy) {
    this->type = copy.type;
    return *this;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "Called default destructor of WrongAnimal" << std::endl;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "Default sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return this->type;
}
