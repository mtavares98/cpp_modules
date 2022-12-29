/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:28:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/25 13:37:14 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	rawBits;
		static const int	numberBits = 8;
	public:
		Fixed(void);
		Fixed(Fixed const &copy);
		Fixed &operator=(Fixed const &copy);
		~Fixed(void);
		Fixed(const int rawBits);
		Fixed(const float rawBits);
		int	getRawBits(void) const;
		void	setRawBits( int const raw);
		float	toFloat(void);
		int		toInt(void);
};
std::ostream &operator<<(std::ostream &out, Fixed const &value);
#endif
