#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
   public:
   Zombie(void);
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
    void setName(std::string name);

   private:
    std::string name;
};

#endif /* ********************************************************** ZOMBIE_H */
