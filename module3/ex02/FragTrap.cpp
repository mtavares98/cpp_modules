/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:17:57 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/29 15:48:17 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "Called default constructor from FragTrap" << std::endl;
    this->name = "";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) {
    std::cout << "Called constructor with name from FragTrap" << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
    *this = copy;
}

FragTrap& FragTrap::operator=(FragTrap const& copy) {
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "Called default destructor from FragTrap" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name << " request a positive high fives" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->energyPoints < 1) {
        std::cout << "There is no more energy points available" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}

void FragTrap::beRepaired(unsigned int amount) {
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
    std::cout << "FragTrap " << this->name << " Repaired " << amount << " Now is having " << this->hitPoints << std::endl;
}
