/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:09:37 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/20 22:19:00 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"



HumanB::HumanB(std::string const & name)
{
	std::cout << "Called standard HumanB constructor\n";
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB(void)
{
	std::cout << "Called standard HumanB destructor\n";
}

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their ";
	if (this->weapon)
		std::cout << this->weapon->getType() << '\n';
	else
		std::cout << "bare hands\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
