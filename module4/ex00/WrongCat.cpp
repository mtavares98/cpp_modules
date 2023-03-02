/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:58:29 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/02 23:03:47 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
    std::cout << "Called default constructor of WrongCat" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const& copy) : WrongAnimal(copy) {
    *this = copy;
}

WrongCat& WrongCat::operator=(WrongCat const& copy) {
    this->type = copy.type;
    return *this;
}

WrongCat::~WrongCat(void) {
    std::cout << "Called default destructor of WrongCat" << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "Ãoão" << std::endl;
}
