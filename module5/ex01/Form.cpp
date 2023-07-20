/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:03:52 by mtavares          #+#    #+#             */
/*   Updated: 2023/06/27 20:32:49 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name(""),
                   isSigned(false),
                   gradeRequired(150),
                   gradeExec(150) {
   // std::cout << "Called Form default constructor" << std::endl;
}

Form::Form(std::string name, const int gradeRequired, const int gradeExec) : name(name),
                                                                             isSigned(false),
                                                                             gradeRequired(gradeRequired),
                                                                             gradeExec(gradeExec) {
    if (gradeRequired > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
    else if (gradeRequired < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    //std::cout << "Called Form constructor with name and grade" << std::endl;
}

Form::~Form(void) {
    //std::cout << "Called Form default destructor" << std::endl;
}

const std::string &Form::getName(void) const {
    return this->name;
}

const int &Form::getGradeRequired(void) const {
    return this->gradeRequired;
}

const int &Form::getGradeExec(void) const {
    return this->gradeExec;
}

bool Form::getIsSign(void) const {
    return this->isSigned;
}

bool Form::beSigned(Bureaucrat &bureaucrat) {
    if (this->gradeRequired < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
    this->isSigned = true;
    return this->isSigned;
}

Form::Form(Form const &copy) :  name(copy.name),
                                gradeRequired(copy.gradeRequired),
                                gradeExec(copy.gradeExec) {
    *this = copy;
}

Form &Form::operator=(Form const &copy) {
    this->isSigned = copy.getIsSign();
    return *this;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Name: " << form.getName() << ", status: " << form.getIsSign()
       << ", require grade: " << form.getGradeRequired() << " and execution grade: "
       << form.getGradeExec();
    return os;
}
