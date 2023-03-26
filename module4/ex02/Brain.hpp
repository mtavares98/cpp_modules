#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
private:
    std::string ideas[100];

public:
    Brain(void);
    Brain(const std::string &idea);
    Brain(Brain const &copy);
    Brain &operator=(Brain const &copy);
    ~Brain();
};


#endif //BRAIN_HPP
