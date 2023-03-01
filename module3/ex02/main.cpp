/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:03:43 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/01 19:21:41 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    ScavTrap bob = ScavTrap("Bob");
    FragTrap jim = FragTrap("Jim");

    bob.attack(jim.getName());
    jim.takeDamage(bob.getAttack());
    jim.beRepaired(2);
    bob.beRepaired(2);
    bob.guardGate();
    jim.highFivesGuys();
    std::cout << std::endl;
    ScavTrap bob2 = ScavTrap(bob);
    FragTrap jim2 = FragTrap(jim);
    bob2.attack(jim2.getName());
    jim2.takeDamage(bob2.getAttack());
    jim2.beRepaired(2);
    bob2.beRepaired(2);
    bob2.guardGate();
    jim2.highFivesGuys();
}
