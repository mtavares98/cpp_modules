//
// Created by mtavares on 9/6/23.
//

#include "Span.hpp"
#include <algorithm>

Span::Span(void) : _numbers(0), _maxNumbers(0) {}

Span::Span(unsigned int maxNumbers) : _numbers(0), _maxNumbers(maxNumbers) {}

Span::Span(Span const &copy) : _numbers(0), _maxNumbers(copy._maxNumbers) {
    *this = copy;
}

Span &Span::operator=(Span const &copy) {
    this->_maxNumbers = copy._maxNumbers;
    this->_numbers = copy._numbers;
    return *this;
}

Span::~Span(void) {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxNumbers) {
        throw Span::SizeTooHigh();
    }
    _numbers.push_back(number);
}

int Span::longestSpan() {
    if (_numbers.size() <= 2)
        throw Span::LowNumbers();
    std::sort(_numbers.begin(), _numbers.end());
    return _numbers.back() - _numbers.front();
}

int Span::shortestSpan() {
    int res = 0;

    if (_numbers.size() <= 2)
        throw Span::LowNumbers();
    std::sort(_numbers.begin(), _numbers.end());
    res = longestSpan();
    for(std::vector<int>::iterator it = _numbers.begin(); it != _numbers.end() - 1; it++) {
        if (res > *(it + 1) - *it)
            res = *(it + 1) - *it;
    }
    return res;
}

const char *Span::LowNumbers::what() const throw() { return "Does not have enough size"; }

const char *Span::SizeTooHigh::what() const throw() { return "Can not add another number"; }