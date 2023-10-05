/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:09:49 by mtavares          #+#    #+#             */
/*   Updated: 2023/10/05 16:38:30 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate(void) {
    switch (rand() % 3) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Not valid type" << std::endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e) {
        try {
            (void)dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e) {
            try {
                (void)dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e) {
                std::cout << "Not valid type" << std::endl;
            }
        }
    }
}

int main(void) {
    Base *b;

    for(int i = 0; i < 100; i++) {
        b = generate();
        identify(*b);
        identify(b);
        delete b;
    }
    Base tmp;
    identify(tmp);
    identify(&tmp);
}
