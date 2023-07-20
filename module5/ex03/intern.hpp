/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:33:19 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/20 13:20:26 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    public:
        Intern(void);
        Intern(Intern const &copy);
        Intern &operator=(Intern &copy);
        ~Intern(void);
        AForm *makeForm(const std::string &nameForm, const std::string &target);
        class FormNotCreated : public std::exception {
            public:
                const char *what(void) const throw();
        };
};

#endif
