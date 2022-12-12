/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:06:06 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/12 00:19:38 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <stdlib.h>

typedef struct s_data	t_data;

struct s_data
{
	std::string msg;
	std::string value;
};

class Contact
{
	private:
		std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
		void	getNewContact(const Contact &c, int index);
	public:
		Contact(void);
		Contact(t_data *data);
		~Contact(void);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif
