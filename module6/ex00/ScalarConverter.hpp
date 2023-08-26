/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:27:12 by mtavares          #+#    #+#             */
/*   Updated: 2023/08/26 15:22:56 by mtavares         ###   ########.fr       */
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
    static int checkChar(const std::string &input);
    static int checkInt(const std::string &input);
    static int checkDecimal(const std::string &input);
    static void getNumsFromChar(const std::string &input);
    static void getNumsFromInt(const std::string &input);
    static void getNumsFromFloat(const std::string &input);
    static void getNumsFromDouble(const std::string &input);
    static void display_values(char c, int i, float f, double d, char possible);
    static int getType(const std::string &input);

   public:
    static void converter(const std::string &input);
    class ImpossibleConvertion : public std::exception {
        const char *what(void) const throw();
    };
    class ValidArgs : public std::exception {
        const char *what(void) const throw();
    };
};
#endif
