/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:37:59 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/28 17:37:59 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

int main(void) {
    ClapTrap bob = ClapTrap("Bob");
    ClapTrap jim = ClapTrap("Jim");
    ClapTrap bobCpy =ClapTrap(bob);

    bob.attack(jim.getName());
    jim.takeDamage(bob.getAttack());
    bobCpy.attack(jim.getName());
    jim.takeDamage(bobCpy.getAttack());
    jim.beRepaired(2);
}
