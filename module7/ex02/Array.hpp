//
// Created by mtavares on 9/3/23.
//

#ifndef EX02_ARRAY_HPP
#define EX02_ARRAY_HPP

template <typename T>
class Array {
private:
    T *_array;
    unsigned int _size;
public:
    Array();
    Array(unsigned int size);
    Array(const Array &copy);
    Array<T> &operator=(const Array &copy);
    ~Array();
    T &operator[](unsigned int pos);
    unsigned int size();
};

#endif //EX02_ARRAY_HPP
