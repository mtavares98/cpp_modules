/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:37:59 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/29 14:05:38 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap bob = ClapTrap("Bob");
    ClapTrap jim = ClapTrap("Jim");
    ClapTrap bobCpy =ClapTrap(bob);

    for (int i = 0; i < 10; i++) {
        bob.attack(jim.getName());
        jim.takeDamage(bob.getAttack());
    }
     bob.attack(jim.getName());
    for (int i = 0; i < 10; i++) {
        bobCpy.attack(jim.getName());
        jim.takeDamage(bobCpy.getAttack());
    }
    bobCpy.attack(jim.getName());
    jim.beRepaired(2);
}

