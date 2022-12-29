/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:09:26 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/25 13:27:49 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
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
		int	getRawBits(void) const;
		void	setRawBits( int const raw);
};
#endif
