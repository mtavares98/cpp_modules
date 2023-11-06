/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:50:13 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/03 15:27:05 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
class RPN {
 private:
  RPN(void);
  bool isOperator(char op);
  void executeOperation(char op);
  std::stack<int> _numbers;

 public:
  RPN(char *av);
  RPN(RPN const &copy);
  RPN &operator=(RPN const &copy);
  ~RPN(void);
};
#endif
