//
// Created by mtavares on 9/7/23.
//

#ifndef EX02_MUTANTSTACK_HPP
#define EX02_MUTANTSTACK_HPP


#include <stack>


template<typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type ::reverse_iterator reverse_iterator;
    MutantStack();
    MutantStack(const MutantStack<T> &copy);
    MutantStack<T> &operator=(const MutantStack<T> &copy);
    ~MutantStack();
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
};

#include "MutantStack.tpp"

#endif //EX02_MUTANTSTACK_HPP
