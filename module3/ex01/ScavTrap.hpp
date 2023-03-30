/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:40:40 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/29 15:09:14 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <limits>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
   public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &copy);
    ScavTrap &operator=(ScavTrap const &copy);
    ~ScavTrap();

    void guardGate(void);
    void attack(const std::string &target);
    void beRepaired(unsigned int amount);
};

#endif
