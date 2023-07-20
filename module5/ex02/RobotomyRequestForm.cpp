/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:30:59 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/19 22:21:30 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), target(copy.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &copy) {
    copy.setIsSign(this->getIsSign());
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    int num;

    if (!this->getIsSign())
        throw RobotomyRequestForm::NotSign();
    else if (executor.getGrade() > this->getGradeExec())
        throw RobotomyRequestForm::GradeTooLowException();
    srand(time(NULL));
    std::cout << "Makes some drilling noises" << std::endl;
    num = rand() % 2;
    if (!num)
        std::cout << this->getName() << " has been robotomized successfully" << std::endl;
    else
        std::cerr << this->getName() << " robotomization failed." << std::endl;
}

const char *RobotomyRequestForm::NotSign::what(void) const throw() {
    return "RobotomyRequestForm not signed";
}
