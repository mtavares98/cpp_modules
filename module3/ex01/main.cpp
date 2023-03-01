/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:03:43 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/01 19:10:55 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    ScavTrap bob = ScavTrap("Bob");
    ClapTrap jim = ClapTrap("Jim");

    bob.attack(jim.getName());
    jim.takeDamage(bob.getAttack());
    jim.beRepaired(2);
    bob.beRepaired(2);
    bob.guardGate();
    std::cout << std::endl;
    ScavTrap bob2 = ScavTrap(bob);
    ClapTrap jim2 = ClapTrap(jim);
    bob2.attack(jim2.getName());
    jim2.takeDamage(bob2.getAttack());
    jim2.beRepaired(2);
    bob2.beRepaired(2);
    bob2.guardGate();
}
