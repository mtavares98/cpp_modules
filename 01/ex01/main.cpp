/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:49:08 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/19 21:50:52 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie = zombieHorde(5, "bob");

	for(int i =0; i < 5; i++) {
		zombie[i].announce();
	}
	delete[] zombie;
}
