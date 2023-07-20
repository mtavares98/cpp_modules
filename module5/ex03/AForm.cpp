/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:03:52 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/19 21:40:36 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name(""),
                     isSigned(false),
                     gradeRequired(150),
                     gradeExec(150) {
    // std::cout << "Called AForm default constructor" << std::endl;
}

AForm::AForm(std::string name, const int gradeRequired, const int gradeExec) : name(name),
                                                                               isSigned(false),
                                                                               gradeRequired(gradeRequired),
                                                                               gradeExec(gradeExec) {
    if (gradeRequired > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
    else if (gradeRequired < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    // std::cout << "Called AForm constructor with name and grade" << std::endl;
}

AForm::~AForm(void) {
    // std::cout << "Called AForm default destructor" << std::endl;
}

const std::string &AForm::getName(void) const {
    return this->name;
}

const int &AForm::getGradeRequired(void) const {
    return this->gradeRequired;
}

const int &AForm::getGradeExec(void) const {
    return this->gradeExec;
}

bool AForm::getIsSign(void) const {
    return this->isSigned;
}

void AForm::setIsSign(bool isSign) {
    this->setIsSign(isSign);
}

bool AForm::beSigned(Bureaucrat &bureaucrat) {
    if (this->gradeRequired < bureaucrat.getGrade())
        throw AForm::GradeTooLowException();
    this->isSigned = true;
    return this->isSigned;
}

AForm::AForm(AForm const &copy) : name(copy.name),
                                  gradeRequired(copy.gradeRequired),
                                  gradeExec(copy.gradeExec) {
    *this = copy;
}

AForm &AForm::operator=(AForm const &copy) {
    this->isSigned = copy.getIsSign();
    return *this;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Name: " << form.getName() << ", status: " << form.getIsSign()
       << ", require grade: " << form.getGradeRequired() << " and execution grade: "
       << form.getGradeExec();
    return os;
}
