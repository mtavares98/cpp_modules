/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:23:09 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/11 00:30:06 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	int	i = 0;

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
	for(int i = 0; i < 8; i++)
		this->data[i].value = "";
	std::cout << "Deleting the phonebook" << '\n';
}

void PhoneBook::ADD(void)
{
	int i;

	for (i = 0; i < 8; i++) {
		std::cout << this->data[i].msg << '\n';
		std::cin >> this->data[i].value;
		if (this->data[i].value.empty()) {
			std::cout << "Failed creating a contact all information is required\n";
			return ;
		}
	}
	Contact tmp = Contact(this->data);
	if (c[this->index].getFirstName().empty())
		c[this->index++] = tmp;
	else {
		c[this->index].~Contact();
		c[this->index++] = tmp;
	}
	if (this->index == 9)
		this->index = 0;
	if (this->size != 8)
		this->size++;
}

/*
	Print header |     index|  fistName|  lastName|  nickname|
	print body with correct parameters
	recive an user input to give an index to print the correct contact if exists
*/

void PhoneBook::SEARCH(void)
{
	std::cout << "Entrou no search" << '\n';
}

void PhoneBook::	EXIT(void)
{
	for (int i = 0; i < 8; i++) {
		if (!this->c[i].getFirstName().empty())
			this->c[i].~Contact();
		else
			break ;
	}
	this->~PhoneBook();
	exit(EXIT_SUCCESS);
}
