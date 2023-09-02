//
// Created by mtavares on 9/2/23.
//

#include <iostream>
#include "iter.h"

template <typename T>
void addOne(T& a)
{
    ++a;
}

template <typename T>
void printArr(T& b)
{
    std::cout << b << std::endl;
}

void modifyStr(std::string& a)
{
    a += " b";
}


int main()
{
    int a[] = {
            1,
            8,
            3,
            2,
            5,
            12
    };

    ::iter(a, 6, printArr);
    std::cout << "---" << std::endl;
    ::iter(a, 6, addOne);
    ::iter(a, 6, printArr);
    std::cout << "\n";

    std::string b[] = {
            "hello",
            "world",
            "!"
    };
    ::iter(b, 3, printArr);
    std::cout << "---" << std::endl;
    ::iter(b, 3, modifyStr);
    ::iter(b, 3, printArr);
}