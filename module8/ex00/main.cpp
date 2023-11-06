//
// Created by mtavares on 9/5/23.
//

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    {
        std::vector<int> v;

        for (int i = 0; i < 10; i++) {
            v.push_back(i);
        }
        std::cout << "Vector container: ";
        for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        try {
            std::cout << *easyfind(v, 0) << std::endl;
            std::cout << *easyfind(v, 10) << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::list<int> l;

        for (int i = 0; i < 10; i++) {
            l.push_front(i);
        }
        std::cout << "List container: ";
        for (std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        try {
            std::cout << *easyfind(l, 0) << std::endl;
            std::cout << *easyfind(l, 10) << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}