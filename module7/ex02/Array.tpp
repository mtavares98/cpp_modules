//
// Created by mtavares on 9/3/23.
//

#ifndef EX02_ARRAY_TPP
#define EX02_ARRAY_TPP

#include <cstring>
#include <iostream>

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]()), _size(size){}

template<typename T>
Array<T>::Array(const Array &copy) : _array(NULL), _size(0) { *this = copy; }

template<typename T>
Array<T> &Array<T>::operator=(const Array &copy) {
    delete[] _array;
    _size = copy._size;
    _array = new T[_size]();
    std::memmove(_array, copy._array, sizeof(T) * _size);
    return *this;
}

template<typename T>
Array<T>::~Array() { delete[] _array; }

template<typename T>
T &Array<T>::operator[](unsigned int pos) {
    if (pos >= _size)
        throw std::range_error("Out of bounds");
    return _array[pos];
}

template<typename T>
unsigned int Array<T>::size() { return _size; }

#endif //EX02_ARRAY_TPP
