/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:05:39 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/20 13:30:29 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "intern.hpp"

int main(void) {
    AForm* scf;
    try {
        Intern someRandomIntern;
        scf = someRandomIntern.makeForm("Shrubbery creation", "home");

        Bureaucrat b1("jardineiro", 137);
        b1.signForm(*scf);
        b1.executeForm(*scf);
        delete scf;
    } catch (std::exception& e) {
        std::cout << "Failed because: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    AForm* rrf;
    try {
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("Robotomy request", "Bender");

        Bureaucrat b1("DoctorRobotomizer", 45);
        b1.signForm(*rrf);
        b1.executeForm(*rrf);
        delete rrf;
    } catch (std::exception& e) {
        std::cout << "Failed because: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    AForm* ppf;
    try {
        Intern someRandomIntern;
        ppf = someRandomIntern.makeForm("Presidential pardon", "condemned");

        Bureaucrat b1("Presidente", 5);
        b1.signForm(*ppf);
        b1.executeForm(*ppf);
        delete ppf;
    } catch (std::exception& e) {
        std::cout << "Failed because: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    AForm* wrong;
    try {
        Intern someRandomIntern;
        wrong = someRandomIntern.makeForm("wrong", "doesn't really matter");

        Bureaucrat b1("burocrata", 1);
        b1.signForm(*wrong);
        b1.executeForm(*wrong);
        delete wrong;
    } catch (std::exception& e) {
        std::cout << "Failed because: " << e.what() << std::endl;
    }
}
