/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:45:36 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/10 19:09:21 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie* zombieHorde(int n, std::string name) {
    Zombie* horde;

    horde = new Zombie[n];
    for (int i = 0; i < n; i++) {
        horde[i].setName(name);
    }
    return (horde);
}
