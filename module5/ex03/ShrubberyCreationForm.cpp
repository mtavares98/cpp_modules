/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:30:59 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/20 13:17:05 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), target(copy.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &copy) {
    copy.setIsSign(this->getIsSign());
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    std::ofstream outFile;
    std::string fileName;

    if (!this->getIsSign())
        throw ShrubberyCreationForm::NotSign();
    else if (executor.getGrade() > this->getGradeExec())
        throw ShrubberyCreationForm::GradeTooLowException();
    outFile.open((getName() + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
    if (!outFile.is_open())
        throw std::runtime_error("Cannot create the file");
    outFile << "               ,@@@@@@@," << std::endl;
    outFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    outFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    outFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    outFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    outFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    outFile << "       |o|        | |         | |" << std::endl;
    outFile << "       |.|        | |         | |" << std::endl;
    outFile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
    outFile.close();
}

const char *ShrubberyCreationForm::NotSign::what(void) const throw() {
    return "ShrubberyCreationForm not signed";
}
