/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:09:15 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/08 22:16:30 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie* newZombie( std::string name ) {
    Zombie *zombie = new Zombie(name);

    return zombie;
}

void randomChump( std::string name ) {
    Zombie zombie = Zombie(name);

    zombie.announce();
}

int main(void) {
    Zombie *zombie = newZombie("Pro");

    randomChump("Bob");
    zombie->announce();
    delete zombie;
}
