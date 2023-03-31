/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:03:43 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/31 15:44:33 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    ScavTrap bob = ScavTrap("Bob");
    FragTrap jim = FragTrap("Jim");

    jim.highFivesGuys();
    for (int i = 0; i < 100; i++) {
        if (i % 5 == 0)
            bob.beRepaired(100);
        jim.attack(bob.getName());
        bob.takeDamage(jim.getAttack());
    }
}
