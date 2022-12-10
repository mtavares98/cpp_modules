/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:11:03 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/10 22:40:36 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact c[8];
		t_data data[5];
		int	index, size;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void ADD(void);
		void SEARCH(void);
		void EXIT(void);
};

#endif
