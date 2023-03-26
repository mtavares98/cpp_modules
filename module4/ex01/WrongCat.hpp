/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:56:19 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/02 23:03:55 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
   public:
    WrongCat(void);
    WrongCat(WrongCat const &copy);
    WrongCat &operator=(WrongCat const &copy);
    ~WrongCat(void);

	void makeSound(void) const;
};

#endif
