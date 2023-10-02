/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:50:43 by mtavares          #+#    #+#             */
/*   Updated: 2023/08/26 15:13:07 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Only receive one argument" << std::endl;
        return (1);
    }
    try {
        ScalarConverter::converter((const std::string)av[1]);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
