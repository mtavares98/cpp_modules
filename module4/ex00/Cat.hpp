#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal {
   public:
    Cat(void);
    Cat(Cat const &copy);
    Cat &operator=(Cat const &copy);
    ~Cat(void);

	void makeSound(void) const;
};

#endif
