/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:28:49 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/25 13:38:27 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->rawBits = 0;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called\n";
	this->operator=(copy);
}

Fixed &Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called\n";
	this->setRawBits(copy.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int rawBits)
{
}

Fixed::Fixed(const float rawBits)
{
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

float Fixed::toFloat(void)
{
return 0.0f;
}

int Fixed::toInt(void)
{
return 0;
}

std::ostream & operator<<(std::ostream & out, Fixed const & value)
{
	std::cout << value.
	return (out);
}
