/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:16:35 by mtavares          #+#    #+#             */
/*   Updated: 2023/10/05 16:25:15 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <float.h>

void ScalarConverter::converter(const std::string &input) {
    int type;

    type = getType(input);
    if (type == -1)
        throw ScalarConverter::ValidArgs();
    try {
        switch (type) {
            case 0:
                getNumsFromChar(input);
                break;
            case 1:
                getNumsFromInt(input);
                break;
            case 2:
                getNumsFromFloat(input);
                break;
            case 3:
                getNumsFromDouble(input);
                break;
        }
    }
    catch (std::exception &e) {
        throw;
    }
}

int ScalarConverter::getType(const std::string &input) {
    int type = -1;

    type = checkChar(input);
    if (type != -1)
        return type;
    type = checkInt(input);
    if (type != -1)
        return type;
    type = checkDecimal(input);
    return type;
}

int ScalarConverter::checkChar(const std::string &input) {
    if (input.length() == 1 && !isdigit(input[0]))
        return CHAR;
    return -1;
}

int ScalarConverter::checkInt(const std::string &input) {
    int i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;
    if (!input[i])
        return -1;
    for (; isdigit(input[i]); i++)
        ;
    if (input[i] != '\0')
        return -1;
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
    if (input[i] == '.') {
        foundPoint = true;
        i++;
    }
    for (; isdigit(input[i]); i++)
        ;
    if (foundPoint == true && input[i] == 'f' && i + 1 == (int)input.length())
        return FLOAT;
    else if (foundPoint == true && input[i] == '\0' && i == (int)input.length())
        return DOUBLE;
    return -1;
}

void ScalarConverter::getNumsFromChar(const std::string &input) {
    char c;
    int i;
    float f;
    double d;

    c = input[0];
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);
    ScalarConverter::display_values(c, i, f, d, 0);
}

void ScalarConverter::getNumsFromInt(const std::string &input) {
    char c = 0;
    long int i;
    float f;
    double d;

    i = std::strtol(input.c_str(), NULL, 10);
    if (i > INT_MAX || i < INT_MIN || errno == ERANGE)
        throw ScalarConverter::ImpossibleConvertion();
    c = static_cast<char>(i);
    f = static_cast<float>(i);
    d = static_cast<double>(i);
    ScalarConverter::display_values(c, i, f, d, 0);
}

void ScalarConverter::getNumsFromFloat(const std::string &input) {
    char c = 0;
    int i = 0;
    float f = 0;
    double d = 0;
    char possible = 0;

    d = strtod(input.c_str(), NULL);
    if (d < FLT_MIN || d > FLT_MAX)
        throw ScalarConverter::ImpossibleConvertion();
    f = static_cast<float>(d);
    if (input == "nanf" || input == "+inff" || input == "-inff") {
        possible = 2;
    } else if (INT_MIN > static_cast<long int>(f) || INT_MAX < static_cast<long int>(f)) {
        possible = 2;
    } else if (CHAR_MIN > static_cast<int>(f) || CHAR_MAX < static_cast<int>(f)) {
        possible = 1;
        i = static_cast<int>(f);
    }
    else {
        c = static_cast<char>(f);
        i = static_cast<int>(f);
    }
    d = static_cast<double>(f);
    ScalarConverter::display_values(c, i, f, d, possible);
}

void ScalarConverter::getNumsFromDouble(const std::string &input) {
    char c = 0;
    int i = 0;
    float f = 0;
    double d = 0;
    char possible = 0;

    d = strtod(input.c_str(), NULL);
    if (errno == ERANGE)
        throw ScalarConverter::ImpossibleConvertion();
    if (input == "nan" || input == "+inf" || input == "-inf") {
        possible = 2;
    }
    else if (INT_MIN > static_cast<long int>(d) || INT_MAX < static_cast<long int>(d)) {
        possible = 2;
    }
    else if (CHAR_MIN > static_cast<int>(d) || CHAR_MAX < static_cast<int>(d)) {
        possible = 1;
        i = static_cast<int>(d);
    } else {
        c = static_cast<char>(d);
        i = static_cast<int>(d);
    }
    f = static_cast<float>(d);
    ScalarConverter::display_values(c, i, f, d, possible);
}

void ScalarConverter::display_values(char c, int i, float f, double d, char possible) {
    std::cout << "Char: ";
    if (possible > 0)
        std::cout << "impossible" << std::endl;
    else if (c < 32 || c > 126)
        std::cout << " non displayable" << std::endl;
    else
        std::cout << c << std::endl;
    std::cout << "Int: ";
    if (possible > 1)
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) <<  f << 'f' << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

const char *ScalarConverter::ImpossibleConvertion::what(void) const throw() {
    return "Convertion impossible due to range";
}

const char *ScalarConverter::ValidArgs::what(void) const throw() {
    return "Invalid Argument";
}

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    (void)copy;
    return *this;
}

ScalarConverter::~ScalarConverter() {}
