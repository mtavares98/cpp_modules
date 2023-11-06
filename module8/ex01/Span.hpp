/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:50:39 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/06 15:50:40 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
  std::vector<int> _numbers;
  unsigned int _maxNumbers;

public:
  Span(void);
  Span(unsigned int maxNumbers);
  Span(Span const &copy);
  Span &operator=(Span const &copy);
  ~Span(void);
  void addNumber(int number);
  int longestSpan();
  int shortestSpan();
  class LowNumbers : public std::exception {
    const char *what() const throw();
  };
  class SizeTooHigh : public std::exception {
    const char *what() const throw();
  };
  template <typename T>
  void addNumbers(const typename T::iterator &begin,
                  const typename T::iterator &end) {
    for (typename T::iterator i = begin; i != end; i++) {
      addNumber(*i);
    }
  }
};
#endif
