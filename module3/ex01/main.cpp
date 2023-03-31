/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:03:43 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/31 16:17:17 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

int main(void) {
    ScavTrap bob = ScavTrap("Bob");
    ScavTrap jim = ScavTrap("Jim");
    ScavTrap bobCopy = ScavTrap(bob);

    for (int i = 0; i < 50; i++) {
        if (i % 5 == 0)
            jim.beRepaired(100);
        bob.attack(jim.getName());
        jim.takeDamage(bob.getAttack());
    }
    bob.attack(jim.getName());
    bob.beRepaired(1);
    jim.beRepaired(0);
}
