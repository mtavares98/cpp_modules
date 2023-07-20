/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:01:26 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/19 22:11:05 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        const std::string &target;
   public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(RobotomyRequestForm const &copy);
    RobotomyRequestForm &operator=(RobotomyRequestForm &copy);
    ~RobotomyRequestForm(void);
    void execute(Bureaucrat const &executor) const;
    class NotSign : public std::exception {
        public:
            const char *what(void) const throw();
    };
};

#endif
