/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:43:07 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/19 21:54:31 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name(""), grade(150) {
    // std::cout << "Called Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    // std::cout << "Called Bureaucrat constructor with name and grade" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy) : name(copy.name), grade(copy.grade) {
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& copy) {
    grade = copy.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {
    // std::cout << "Called Bureaucrat default destructor" << std::endl;
}

const std::string& Bureaucrat::getName(void) const {
    return this->name;
}

const int& Bureaucrat::getGrade(void) const {
    return this->grade;
}

void Bureaucrat::incrementGrade(void) {
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(AForm& form) {

    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << this->name << " couldn't signed " << form.getName() << " because ";
        std::cerr << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) {
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}
