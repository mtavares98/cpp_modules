/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:52:24 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/07 17:05:44 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        Contact();
        ~Contact();
        void setFirstName(std::string newName);
        std::string getFirstName(void);
        void setLastName(std::string newLastName);
        std::string getLastName(void);
        void setNickname(std::string newNickname);
        std::string getNickname(void);
        void setPhoneNumber(std::string newPhoneNumber);
        std::string getPhoneNumber(void);
        void setDarkestSecret(std::string newDarkestSecret);
        std::string getDarkestSecret(void);
};
