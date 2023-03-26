#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain *brain;

    public:
        Dog(void);
        Dog(const std::string &idea);
        Dog(Dog const &copy);
        Dog &operator=(Dog const &copy);
        ~Dog(void);

	void makeSound(void) const;
};
#endif
