/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:49:13 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/02 23:01:36 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
    std::cout << "Called default constructor of Dog" << std::endl;
    this->type = "Dog";
}

Dog::Dog(Dog const& copy) : Animal(copy) {
    *this = copy;
}

Dog& Dog::operator=(Dog const& copy) {
    this->type = copy.type;
    return *this;
}

Dog::~Dog(void) {
    std::cout << "Called default destructor of Dog" << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "Ãoão" << std::endl;
}
