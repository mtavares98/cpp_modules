/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:24:34 by mtavares          #+#    #+#             */
/*   Updated: 2023/07/19 22:25:20 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        const std::string &target;
   public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(PresidentialPardonForm const &copy);
    PresidentialPardonForm &operator=(PresidentialPardonForm &copy);
    ~PresidentialPardonForm(void);
    void execute(Bureaucrat const &executor) const;
    class NotSign : public std::exception {
        public:
            const char *what(void) const throw();
    };
};

#endif
