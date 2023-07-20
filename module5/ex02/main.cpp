/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:05:39 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/19 22:31:05 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    try {
        Bureaucrat b1("Senhor executor burocrata", 143);
        AForm *f1 = new ShrubberyCreationForm("home");
        std::cout << *f1 << std::endl << std::endl;
        b1.signForm(*f1);
        b1.executeForm(*f1);
        delete f1;
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b1("Senhor doutor", 46);
        AForm *f1 = new RobotomyRequestForm("paciente");
        std::cout << *f1 << std::endl << std::endl;
        b1.signForm(*f1);
        b1.executeForm(*f1);
        delete f1;
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try // sign: 25 exec: 5
    {
        Bureaucrat b1("Burocrata de alto nivel", 21);
        AForm *f1 = new PresidentialPardonForm("krikit warrior");
        std::cout << *f1 << std::endl << std::endl;
        b1.signForm(*f1);
        b1.executeForm(*f1);
        delete f1;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
