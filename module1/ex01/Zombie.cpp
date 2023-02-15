#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie(void) {
	std::cout << "Default constructor called" << std::endl;
}

Zombie::Zombie(std::string name) {
    this->name = name;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie() {
	std::cout << "Default destructor called" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
