/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:41:10 by mtavares          #+#    #+#             */
/*   Updated: 2023/06/25 15:25:08 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
   private:
    std::string const name;
    bool isSigned;
    const int gradeRequired;
    const int gradeExec;

   public:
    Form(void);
    Form(std::string name, const int gradeRequired, const int gradeExec);
    Form(Form const &copy);
    Form &operator=(Form const &copy);
    ~Form(void);
    const std::string &getName(void) const;
    const int &getGradeRequired(void) const;
    const int &getGradeExec(void) const;
    bool getIsSign(void) const;
    bool beSigned(Bureaucrat &bureaucrat);
    class GradeTooHighException : public std::exception {
       public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif
