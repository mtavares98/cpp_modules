/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:23:05 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/13 15:13:37 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

Contact::Contact(t_data *data)
{
	this->firstName = data[0].value;
	this->lastName = data[1].value;
	this->nickname = data[2].value;
	this->phoneNumber = data[3].value;
}

Contact::~Contact(void)
{
	std::cout << "Deleting a Contact" << '\n';
}

std::string Contact::getFirstName()
{
	return this->firstName;
}

void Contact::setContact(t_data *data)
{
	this->setFirstName(data[0].value);
	this->setLastName(data[1].value);
	this->setNickname(data[2].value);
	this->setPhoneNumber(data[3].value);
	this->setDarkestSecret(data[4].value);
}

std::string Contact::getLastName()
{
	return this->lastName;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

std::string Contact::getPhoneNumber()
{
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return this->darkestSecret;
}

std::string Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;

	return this->firstName;
}

std::string Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;

	return this->lastName;
}

std::string Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;

	return this->nickname;
}

std::string Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;

	return this->phoneNumber;
}

std::string Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;

	return darkestSecret;
}
