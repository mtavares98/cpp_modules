/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:41:10 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/19 20:01:32 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
   private:
    std::string name;
    bool isSigned;
    int gradeRequired;
    int gradeExec;

   public:
    AForm(void);
    AForm(std::string name, const int gradeRequired, const int gradeExec);
    AForm(AForm const &copy);
    AForm &operator=(AForm const &copy);
    virtual ~AForm(void);
    const std::string &getName(void) const;
    const int &getGradeRequired(void) const;
    const int &getGradeExec(void) const;
    bool getIsSign(void) const;
    void setIsSign(bool isSign);
    bool beSigned(Bureaucrat &bureaucrat);
    class GradeTooHighException : public std::exception {
       public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        const char *what() const throw();
    };
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
