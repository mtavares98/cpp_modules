/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:33:40 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/19 21:48:45 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Standard constructor called\n";
}

Zombie::~Zombie(void)
{
	std::cout << "Standard destructor called\n";
}

void	Zombie::announce(void)
{
	std::cout << this->name;
	std::cout << ": BraiiiiiiinnnzzzZ...\n";
}

std::string Zombie::setName(std::string name)
{
	this->name = name;
	return name;
}
