/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:39:22 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/02 23:04:30 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(Animal const &copy);
        Animal &operator=(Animal const &copy);
        virtual ~Animal(void);

        virtual void makeSound(void) const;
        std::string getType(void) const;
};
#endif
