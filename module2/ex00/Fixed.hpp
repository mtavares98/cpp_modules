#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int rawBits;
		static const int fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(Fixed const &copy);
		Fixed &operator=(Fixed const &copy);
		~Fixed(void);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
#endif
