/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:38:11 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/31 16:28:31 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
    std::cout << "Called default constructor" << std::endl;
    this->name = "";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
    std::cout << "Called constructor with name" << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const& copy) {
    *this = copy;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& copy) {
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "Called default destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->energyPoints < 1) {
        std::cout << "There is no more energy points available" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints > amount)
        this->hitPoints -= amount;
    else
        this->hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints < 1) {
        std::cout << "There is no more energy points available" << std::endl;
        return;
    }
    if (amount == 0) {
        std::cout << "You need an amount of at least 1 to recover" << std::endl;
        return;
    }
    if (this->hitPoints == 10) {
        std::cout << "You cannot have more HP" << std::endl;
        return;
    }
    this->hitPoints += amount;
    if (this->hitPoints > 10)
        this->hitPoints = 10;
    this->energyPoints--;
    std::cout << "ClapTrap" << this->name << " Repaired " << amount << " Now is having " << this->hitPoints << std::endl;
}

std::string ClapTrap::getName(void) {
    return this->name;
}

unsigned int ClapTrap::getAttack(void) {
    return this->attackDamage;
}
