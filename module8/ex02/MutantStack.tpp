//
// Created by mtavares on 9/7/23.
//

#ifndef EX02_MUTANTSTACK_TPP
#define EX02_MUTANTSTACK_TPP

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &copy) {
    std::stack<T>::operator=(copy);
    return *this;
}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return this->c.begin(); }

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return this->c.end(); }

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() { return this->c.rbegin(); }

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() { return this->c.rend(); }

#endif //EX02_MUTATEDSTACK_TPP
