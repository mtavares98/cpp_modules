/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:11:18 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/08 21:52:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    std::string input = "";
    PhoneBook phoneBook;

    while (!std::cin.eof()) {
        std::cout << "Enter add, search or exit\n";
        getline(std::cin, input);
        if (std::cin.eof())
            return (1);
        for (int i = 0; input[i] != '\0'; i++) {
            input[i] = (char)tolower(input[i]);
        }
        std::cout << input << std::endl;
        if (input == "add")
            phoneBook.ADD();
        else if (input == "search")
            phoneBook.SEARCH();
        else if (input == "exit")
                return (phoneBook.EXIT());
        else
            std::cout << "Wrong option" << std::endl;
        input = "";
        std::cin.clear();
    }
}
