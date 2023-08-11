/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:16:35 by mtavares          #+#    #+#             */
/*   Updated: 2023/08/07 19:41:22 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) {
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy) {
    (void)copy;
    return *this;
}

ScalarConverter::~ScalarConverter(void) {}

int ScalarConverter::getType(const std::string &input) {
    int type = -1;

    type = checkChar(input);
    if (type != -1)
        return type;
    type = checkInt(input);
    if (type != -1)
        return type;
    type = checkDecimal(input);
    // prepare_args(input, type);
}

bool ScalarConverter::checkChar(const std::string &input) {
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
        return CHAR;
}

bool ScalarConverter::checkInt(const std::string &input) {
    int i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;
    if (!input[i])
        return false;
    for (; isdigit(input[i]); i++)
        ;
    if (input[i] != '\0')
        return false;
    return INT;
}

int ScalarConverter::checkDecimal(const std::string &input) {
    int i = 0;
    bool foundPoint = false;

    if (input == "+inff" || input == "-inff" || input == "nanf")
        return FLOAT;
    else if (input == "+inf" || input == "-inf" || input == "nan")
        return DOUBLE;
    if (input[0] == '+' || input[0] == '-')
        i++;
    for (; isdigit(input[i]); i++)
        ;
    if (input[i] == '.' && input[i + 1] != '\0')
        foundPoint = true;
    for (; isdigit(input[i]); i++)
        ;
    if (foundPoint == true && input[i] == 'f' && i == input.length())
        return FLOAT;
    else if (foundPoint == true && input[i] == '\0')
        return DOUBLE;
    return -1;
}

char ScalarConverter::convertChar(const std::string &input) {
    char res;

    res = static_cast<char>(input[1]);
    return res;
}

int ScalarConverter::convertInt(const std::string &input) {
    int res;

    res = std::strtol(input.c_str(), NULL, 10);
    if (res > INT_MAX || res < INT_MIN || errno == ERANGE)
        throw ScalarConverter::ImpossibleConvertion();
    return res;
}

float ScalarConverter::convertFloat(const std::string &input) {
    float res;

    res = strtof(input.c_str(), NULL);
    if (errno == ERANGE)
        throw ScalarConverter::ImpossibleConvertion();
    return res;
}

double ScalarConverter::convertDouble(const std::string &input) {
    double res;

    res = strtod(input.c_str(), NULL);
    if (errno == ERANGE)
        throw ScalarConverter::ImpossibleConvertion();
    return res;
}

void ScalarConverter::display_values(char c, int i, float f, double d, int type) {
}

const char *ScalarConverter::ImpossibleConvertion::what(void) const throw() {
    return "Convertion impossible due to range";
}

const char *ScalarConverter::ValidArgs::what(void) const throw() {
    return "Invalid Argument";
}
