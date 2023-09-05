//
// Created by mtavares on 9/5/23.
//

#ifndef EX00_EASYFIND_HPP
#define EX00_EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator res = std::find(container.begin(), container.end(), value);

    if (res == container.end())
        throw std::runtime_error("Value not found");
    return res;
}

#endif //EX00_EASYFIND_HPP
