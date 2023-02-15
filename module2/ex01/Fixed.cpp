#include "Fixed.hpp"

Fixed::Fixed(void) {
    std::cout << "Default constructor called" << std::endl;
    this->rawBits = 0;
}

Fixed::Fixed(Fixed const& copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int raw) {
    std::cout << "Int constructor called" << std::endl;
    this->rawBits = raw << Fixed::fractionalBits;
}

Fixed::Fixed(const float raw) {
    std::cout << "Float constructor called" << std::endl;
    this->rawBits = roundf(raw * (1 << Fixed::fractionalBits));
}

Fixed& Fixed::operator=(Fixed const& copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(copy.getRawBits());
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->rawBits / (float)(1 << Fixed::fractionalBits);
}

int Fixed::toInt(void) const {
    return this->rawBits >> Fixed::fractionalBits;
}

std::ostream& operator<<(std::ostream& out, Fixed const& value) {
    out << value.toFloat();
    return out;
}
