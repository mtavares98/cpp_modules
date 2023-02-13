/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:44:30 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/07 16:48:06 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            std::cout << (char)toupper(av[i][j]);
        }
        std::cout << std::endl;
    }
}
