/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:25 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/06 15:38:55 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
  try {
    PmergeMe(argc, argv);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
