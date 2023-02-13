/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:50:38 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/08 15:21:00 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include <iomanip>

struct data {
    std::string value;
};

class PhoneBook
{
    private:
        Contact contact[8];
        int     size;
        int     index;
        struct data data[5];
        void setElement(std::string element, int i);
        void setContact(void);
        void printParameter(std::string str);
        void printTableContent(int index);
        void printTableHeader(void);

    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void ADD();
        void SEARCH();
        int EXIT();
};
