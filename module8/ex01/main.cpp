/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:50:05 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/06 15:52:20 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <iostream>

int main() {
  std::cout << ">>> example test <<<" << std::endl;
  {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  std::cout << ">>> trying too small span checking <<<" << std::endl;
  try {
    Span sp(1);
  } catch (std::exception &e) {
    std::cerr << e.what() << "\n";
  }
  try {
    Span sp(0);
  } catch (std::exception &e) {
    std::cerr << e.what() << "\n";
  }
  try {
    Span sp(2);
    sp.shortestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << "\n";
  }
  try {
    Span sp(2);
    sp.longestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << "\n";
  }
  try {
    Span sp(2);
    sp.addNumber(5);
    sp.shortestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << "\n";
  }
  try {
    Span sp(2);
    sp.addNumber(5);
    sp.longestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << "\n";
  }
  try {
    Span sp(2);
    sp.addNumber(5);
    sp.addNumber(8);
    std::cout << sp.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << "\n";
  }

  std::cout << ">>> testing with random numbers <<<" << std::endl;
  {
    std::vector<int> v;
    srand(time(0));
    for (int i = 0; i < 10000; ++i)
      v.push_back(rand());
    Span sp(10000);
    sp.addNumbers<std::vector<int> >(v.begin(), v.end());

    std::cout << "Longest: " << sp.longestSpan() << std::endl;
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
  }
  std::cout << ">>> testing some more cases <<<" << std::endl;
  {
    Span sp = Span(5);

    sp.addNumber(5);
    sp.addNumber(-5);
    sp.addNumber(1);
    sp.addNumber(8);
    sp.addNumber(1);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
}
