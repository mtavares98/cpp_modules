/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:25:32 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/20 13:16:32 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), target(copy.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &copy) {
    copy.setIsSign(this->getIsSign());
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!this->getIsSign())
        throw PresidentialPardonForm::NotSign();
    else if (executor.getGrade() > this->getGradeExec())
        throw PresidentialPardonForm::GradeTooLowException();
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char *PresidentialPardonForm::NotSign::what(void) const throw() {
    return "PresidentialPardonForm not signed";
}
