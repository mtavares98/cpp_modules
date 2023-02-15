/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:12:42 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/10 19:20:46 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
    std::string str = "Hello World";
    std::string *strptr = &str;
    std::string &strref = str;

    std::cout << "Seeing the memory of strings" << std::endl;
    std::cout << &str << std::endl;
    std::cout << &strref << std::endl;
    std::cout << &strptr << std::endl;
    std::cout << "Seeing the strings" << std::endl;
    std::cout << str << std::endl;
    std::cout << strref << std::endl;
    std::cout << *strptr << std::endl;
}
