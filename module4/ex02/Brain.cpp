#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Called default constructor of Brain" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "Default idea";
}

Brain::Brain(const std::string &idea) {
    std::cout << "Called constructor with idea of Brain" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = idea;
}

Brain::Brain(const Brain &copy) {
    *this = copy;
}

Brain &Brain::operator=(const Brain &copy) {
    for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    return *this;
}

Brain::~Brain(void) {
    std::cout << "Called default destructor of Brain" << std::endl;
}