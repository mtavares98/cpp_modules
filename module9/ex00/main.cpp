/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:45:55 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/03 11:22:52 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <iostream>

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  (void)ac;
  try {
    BitcoinExchange btc = BitcoinExchange(av[1]);
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
