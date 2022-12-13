/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:06:06 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/13 15:13:01 by mtavares         ###   ########.fr       */
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
	public:
		Contact(void);
		Contact(t_data *data);
		~Contact(void);
		void	setContact(t_data *data);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		std::string setFirstName(std::string firstName);
		std::string setLastName(std::string lastName);
		std::string setNickname(std::string nickname);
		std::string setPhoneNumber(std::string phoneNumber);
		std::string setDarkestSecret(std::string  darkestSecret);
};

#endif
