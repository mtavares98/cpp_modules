#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int rawBits;
		static const int fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(Fixed const &copy);
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed &operator=(Fixed const &copy);
		~Fixed(void);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
