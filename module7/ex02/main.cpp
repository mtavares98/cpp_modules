//
// Created by mtavares on 9/3/23.
//

#include <iostream>
#include "Array.tpp"

int main()
{
    ::Array<int> a;
    std::cout << a.size() << std::endl;
    ::Array<int> b(5);
    b[0] = 10;
    b[1] = 3;
    b[2] = 8;
    b[3] = 1;
    b[4] = -3;
    a = b;
    std::cout << a.size() << ", " << b.size() << std::endl;
    std::cout << a[0] << ", " << b[0] << std::endl;
    std::cout << a[4] << ", " << b[4] << std::endl;
    try { std::cout << a[5] << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << "\n"; }
    try { std::cout << a[-1] << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << "\n"; }
    b[4] = 12;
    std::cout << a[4] << ", " << b[4] << std::endl;
    {
        const ::Array<int> c(a);
        std::cout << a[1] << std::endl;
    }
}