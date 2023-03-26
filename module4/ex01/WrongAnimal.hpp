#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
   protected:
    std::string type;

   public:
    WrongAnimal(void);
    WrongAnimal(WrongAnimal const &copy);
    WrongAnimal &operator=(WrongAnimal const &copy);
    virtual ~WrongAnimal(void);

    virtual void makeSound(void) const;
    std::string getType(void) const;
};

#endif
