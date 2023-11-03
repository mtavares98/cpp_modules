/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:54:58 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/03 15:31:28 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "RPN.hpp"

int main(int ac, char **av) {
  (void)ac;
  try {
    RPN rpn = RPN(av[1]);
  } catch (std::exception &e) {
    std::cout << "Error" << std::endl;
  }
}
