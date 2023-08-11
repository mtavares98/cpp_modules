/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:27:12 by mtavares          #+#    #+#             */
/*   Updated: 2023/08/06 22:07:35 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

class ScalarConverter {
   private:
    bool checkChar(const std::string &input);
    bool checkInt(const std::string &input);
    int checkDecimal(const std::string &input);
    char convertChar(const std::string &input);
    int convertInt(const std::string &input);
    float convertFloat(const std::string &input);
    double convertDouble(const std::string &input);
    void display_values(char c, int i, float f, double d, int type);

   public:
    ScalarConverter(void);
    ScalarConverter(ScalarConverter const &copy);
    ScalarConverter &operator=(ScalarConverter const &copy);
    ~ScalarConverter(void);
    int getType(const std::string &input);
    class ImpossibleConvertion : public std::exception {
        const char *what(void) const throw();
    };
    class ValidArgs : public std::exception {
        const char *what(void) const throw();
    };
};
#endif
