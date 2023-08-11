/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:50:43 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/31 21:39:26 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    ScalarConverter scalar;
    int status;

    if (ac != 2) {
        std::cerr << "Only recive one argument" << std::endl;
        return (1);
    }
    status = scalar.getType((std::string)av[1]);
    std::cout << "Status: " << status << std::endl;
}
