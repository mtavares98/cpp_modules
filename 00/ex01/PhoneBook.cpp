/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:57:19 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/13 15:29:40 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	this->data[0].msg = "What's the first name?";
	this->data[1].msg = "What's the last name?";
	this->data[2].msg = "What's the nickname?";
	this->data[3].msg = "What's the phone number?";
	this->data[4].msg = "What's the darkest secret?";
	this->index = 0;
	this->size = 0;
}

PhoneBook::~PhoneBook(void)
{
	for(int i = 0; i < 5; i++)
		this->data[i].value = "";
	std::cout << "Deleting the phonebook" << '\n';
}

void PhoneBook::ADD(void)
{
	int i;

	for (i = 0; i < 5; i++) {
		std::cout << this->data[i].msg << '\n';
		std::cin >> this->data[i].value;
		if (this->data[i].value.empty()) {
			std::cout << "Failed creating a contact all information is required\n";
			return ;
		}
	}
	if (!c[this->index].getFirstName().empty())
		c[this->index].~Contact();
	c[this->index].setContact(data);
	if (++this->index == 9)
		this->index = 0;
	if (this->size != 8)
		this->size++;
}

void PhoneBook::printParameter(std::string str)
{
	if (str.length() <= 10) {
		std::cout << std::setw(10) << str;
		return ;
	}
	std::cout << std::setw(9) << str;
	std::cout << std::setw(1) << '.';
	return ;
}

void PhoneBook::printTableContent(int index)
{
	std::cout << "|         ";
	std::cout << index;
	std::cout << '|';
	printParameter(this->c[index].getFirstName());
	std::cout << '|';
	printParameter(this->c[index].getLastName());
	std::cout << '|';
	printParameter(this->c[index].getNickname());
	std::cout << '|';
	std::cout << '\n';
}

void PhoneBook::printTableHeader(void)
{
	std::cout << "|     index|First Name| Last Name|  Nickname|" << '\n';
	std::cout << "|----------|----------|----------|----------|" << '\n';
	for(int i = 0; i < 8; i++) {
		if (this->c[i].getFirstName().empty())
			return ;
		printTableContent(i);
		std::cout << "|----------|----------|----------|----------|" << '\n';
	}
}

void PhoneBook::SEARCH(void)
{
	std::string	tmp;
	std::string	tmp2 = "0123456789";
	int	index;

	if (this->c[0].getFirstName().empty()) {
		std::cout << "There's no contacts\n";
		return ;
	}
	printTableHeader();
	std::cout << "Enter an index of your choice\n";
	std::cin >> tmp;
	for (index = 0; index < (int)tmp.length() && isdigit(tmp[index]); index++);
	if (tmp[index] || tmp.length() != 1) {
		std::cout << "Your input is wrong use only one digit\n";
		return ;
	}
	for (index = 0; tmp[0] != tmp2[index]; index++);
	if (index < 0 || index > 7)
	{
		std::cout << "Your index is out of bounds\n";
		return ;
	}
	if (this->c[index].getFirstName().empty()) {
		std::cout << "Your contact don't exist\n";
		return ;
	}
	std::cout << this->c[index].getFirstName() << '\n';
	std::cout << this->c[index].getLastName() << '\n';
	std::cout << this->c[index].getNickname() << '\n';
	std::cout << this->c[index].getPhoneNumber() << '\n';
	std::cout << this->c[index].getDarkestSecret() << '\n';
}

void PhoneBook::	EXIT(void)
{
	for (int i = 0; i < 8; i++) {
		if (!this->c[i].getFirstName().empty())
			this->c[i].~Contact();
		else
			break ;
	}
	exit(0);;
}
