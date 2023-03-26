/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:39:21 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/02 23:04:24 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
    std::cout << "Called default constructor of Animal" << std::endl;
    this->type = "Animal";
}

Animal::Animal(Animal const& copy) {
    *this = copy;
}

Animal& Animal::operator=(Animal const& copy) {
    this->type = copy.type;
    return *this;
}

Animal::~Animal(void) {
    std::cout << "Called default destructor of Animal" << std::endl;
}

void Animal::makeSound(void) const {
    std::cout << "Default sound" << std::endl;
}

std::string Animal::getType(void) const {
    return this->type;
}
