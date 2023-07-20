/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:42:43 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/19 21:08:08 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
   private:
    const std::string name;
    int grade;

   public:
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &copy);
    Bureaucrat &operator=(Bureaucrat const &copy);
    ~Bureaucrat(void);
    const std::string &getName(void) const;
    const int &getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);
    void signForm(AForm &form);
    class GradeTooHighException : public std::exception {
       public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        const char *what() const throw();
    };
    void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
