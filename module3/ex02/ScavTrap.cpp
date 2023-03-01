/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:53:30 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/01 19:12:31 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "Called default constructor from ScavTrap" << std::endl;
    this->name = "";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) {
    std::cout << "Called constructor with name from ScavTrap" << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
    *this = copy;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& copy) {
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "Called default destructor from ScavTrap" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->energyPoints < 1) {
        std::cout << "There is no more energy points available" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints < 1) {
        std::cout << "There is no more energy points available" << std::endl;
        return;
    }
    if (this->hitPoints == 100) {
        std::cout << "You cannot have more HP" << std::endl;
        return;
    }
    this->hitPoints += amount;
    if (this->hitPoints > 100)
        this->hitPoints = 100;
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name << " Repaired " << amount << " Now is having " << this->hitPoints << std::endl;
}
