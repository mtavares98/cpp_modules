#include "Fixed.hpp"

Fixed::Fixed(void) {
    this->rawBits = 0;
}

Fixed::Fixed(Fixed const& copy) {
    *this = copy;
}

Fixed::Fixed(const int raw) {
    this->rawBits = raw << Fixed::fractionalBits;
}

Fixed::Fixed(const float raw) {
    this->rawBits = roundf(raw * (1 << Fixed::fractionalBits));
}

Fixed& Fixed::operator=(Fixed const& copy) {
    this->setRawBits(copy.getRawBits());
    return *this;
}

Fixed::~Fixed(void) {
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

bool Fixed::operator>(Fixed const& value) {
    Fixed delta = Fixed(0);

    delta.setRawBits(1);
    if (*this == value)
        return false;
    return (this->getRawBits() > value.getRawBits());
}

bool Fixed::operator<(Fixed const& value) {
    Fixed delta = Fixed(0);

    delta.setRawBits(1);
    if (*this == value)
            return false;
    return (this->getRawBits() < value.getRawBits());
}

bool Fixed::operator>=(Fixed const& value) {
    Fixed delta = Fixed(0);

    delta.setRawBits(1);
    return (this->getRawBits() >= value.getRawBits() || this->getRawBits() - delta.getRawBits() >= value.getRawBits() \
    || this->getRawBits() + delta.getRawBits() >= value.getRawBits());
}

bool Fixed::operator<=(Fixed const& value) {
    Fixed delta = Fixed(0);

    delta.setRawBits(1);
    return (this->getRawBits() <= value.getRawBits() || this->getRawBits() - delta.getRawBits() <= value.getRawBits() \
    || this->getRawBits() + delta.getRawBits() <= value.getRawBits());
}

bool Fixed::operator==(Fixed const& value) {
    Fixed delta = Fixed(0);

    delta.setRawBits(1);
    return (this->getRawBits() == value.getRawBits() || this->getRawBits() - delta.getRawBits() == value.getRawBits() \
    || this->getRawBits() + delta.getRawBits() == value.getRawBits());
}

bool Fixed::operator!=(Fixed const& value) {
    return this->getRawBits() != value.getRawBits();
}

Fixed Fixed::operator+(Fixed const& value) {
    Fixed tmp = Fixed(this->toFloat() + value.toFloat());

    return tmp;
}

Fixed Fixed::operator-(Fixed const& value) {
    Fixed tmp = Fixed(this->toFloat() - value.toFloat());

    return tmp;
}

Fixed Fixed::operator*(Fixed const& value) {
    Fixed tmp = Fixed(this->toFloat() * value.toFloat());

    return tmp;
}

Fixed Fixed::operator/(Fixed const& value) {
    Fixed tmp = Fixed(this->toFloat() / value.toFloat());

    return tmp;
}

Fixed Fixed::operator++() {
    this->rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp;

    tmp.setRawBits(this->rawBits);
    this->rawBits++;
    return tmp;
}

Fixed Fixed::operator--() {
    this->rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp;

    tmp.setRawBits(this->rawBits);
    this->rawBits--;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b ? a:b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return ((Fixed &)a < (Fixed &)b ? a:b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a:b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return ((Fixed &)a > (Fixed &)b ? a:b);
}
