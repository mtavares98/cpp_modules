/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:40:11 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/20 13:28:17 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const& copy) {
    (void)copy;
}

Intern& Intern::operator=(Intern& copy) {
    (void)copy;
    return (*this);
}

Intern::~Intern(void) {}

AForm* Intern::makeForm(const std::string& nameForm, const std::string& target) {
    AForm* form = 0;
    int i;
    std::string solution[3] = {"Presidential pardon", "Shrubbery creation", "Robotomy request"};

    for (i = 0; i < 3; i++) {
        if (!solution[i].compare(nameForm))
            break;
    }
    switch (i) {
        case 0:
            try {
                form = new PresidentialPardonForm(target);
            } catch (std::bad_alloc& e) {
                throw e;
            }
            break;
        case 1:
            try {
                form = new ShrubberyCreationForm(target);
            } catch (std::bad_alloc& e) {
                throw e;
            }
            break;
        case 2:
            try {
                form = new RobotomyRequestForm(target);
            } catch (std::bad_alloc& e) {
                throw e;
            }
            break;
        case 3:
            throw Intern::FormNotCreated();
            break;
    }
    return form;
}

const char* Intern::FormNotCreated::what(void) const throw() {
    return "Invalid form name";
}
