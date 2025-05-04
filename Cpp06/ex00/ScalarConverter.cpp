/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:39:58 by stefan            #+#    #+#             */
/*   Updated: 2025/05/03 17:40:10 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>

static bool isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "nanf" ||
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff");
}

static bool isCharLiteral(const std::string& str) {
    return (str.length() == 3 && str.front() == '\'' && str.back() == '\'');
}

static void printChar(double val) {
    if (std::isnan(val) || val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(val)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

static void printInt(double val) {
    if (std::isnan(val) || val < static_cast<double>(std::numeric_limits<int>::min()) ||
        val > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

static void printFloat(double val) {
    float f = static_cast<float>(val);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(double val) {
    std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    double value = 0.0;

    if (isCharLiteral(literal)) {
        value = static_cast<double>(literal[1]);
    }
    else if (isPseudoLiteral(literal)) {
        if (literal == "nanf" || literal == "nan")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf" || literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
    }
    else {
        char* end;
        value = std::strtod(literal.c_str(), &end);
        if (*end != '\0' && !(end == literal.c_str() + literal.length() - 1 && *end == 'f')) {
            std::cout << "Error: invalid literal." << std::endl;
            return;
        }
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

// Private members
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}
