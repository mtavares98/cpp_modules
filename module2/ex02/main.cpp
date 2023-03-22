#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed(5.05f) * Fixed(2));
    Fixed c = Fixed(3);

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    Fixed tmp = Fixed(a);
    std::cout << c << " < " << tmp;
    if (c > a)
        std::cout << " True" << std::endl;
    else
        std::cout << " False" << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a + c << std::endl;
    std::cout << a - c << std::endl;
    std::cout << a / c << std::endl;
    std::cout << a * c << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    return 0;
}
