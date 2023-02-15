/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:09:15 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/10 19:05:51 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie* zombieHorde(int n, std::string name);

int main(void) {
    Zombie *horde = zombieHorde(5, "Bob");

    horde->announce();
    delete[] horde;
}
