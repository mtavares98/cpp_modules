/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:50:07 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/03 16:06:43 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <cctype>
#include <exception>
#include <iostream>
#include <stdexcept>

RPN::RPN(void) {}

RPN::RPN(char *av) {
  for (int i = 0; av[i]; i++) {
    if (isdigit(av[i])) {
      this->_numbers.push(av[i] - '0');
    } else if (isOperator(av[i])) {
      if (this->_numbers.size() < 2) throw std::runtime_error("Error");
      executeOperation(av[i]);
    } else if (av[i] != ' ')
      throw std::runtime_error("Error");
  }
  if (this->_numbers.size() != 1) throw std::runtime_error("Error");
  std::cout << this->_numbers.top() << std::endl;
}

RPN::RPN(RPN const &copy) : _numbers(copy._numbers) {}

RPN &RPN::operator=(RPN const &copy) {
  this->_numbers = copy._numbers;
  return *this;
}

RPN::~RPN(void) {}

bool RPN::isOperator(char op) {
  char sol[5] = "+-*/";

  for (int i = 0; i < 4; i++) {
    if (op == sol[i]) return true;
  }
  return false;
}

void RPN::executeOperation(char op) {
  int num1, num2;

  num2 = this->_numbers.top();
  this->_numbers.pop();
  num1 = this->_numbers.top();
  this->_numbers.pop();
  switch (op) {
    case '+':
      num1 += num2;
      break;
    case '-':
      num1 -= num2;
      break;
    case '*':
      num1 *= num2;
      break;
    default:
      num1 /= num2;
  }
  this->_numbers.push(num1);
}
