//
// Created by mtavares on 9/2/23.
//

#ifndef EX01_ITER_H
#define EX01_ITER_H

template<typename T>
void iter(T *array, unsigned long length, void(*func)(T &)) {
    for (unsigned long i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif //EX01_ITER_H
