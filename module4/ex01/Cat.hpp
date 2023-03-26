#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *brain;

    public:
        Cat(void);
        Cat(const std::string &idea);
        Cat(Cat const &copy);
        Cat &operator=(Cat const &copy);
        ~Cat(void);

	void makeSound(void) const;
};

#endif
