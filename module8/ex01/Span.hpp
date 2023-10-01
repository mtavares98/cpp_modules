//
// Created by mtavares on 9/6/23.
//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
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
        const char * what() const throw();
    };
    class SizeTooHigh : public std::exception {
        const char * what() const throw();
    };
};
#endif
