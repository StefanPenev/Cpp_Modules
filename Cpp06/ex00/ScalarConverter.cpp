/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:39:58 by stefan            #+#    #+#             */
/*   Updated: 2025/06/30 11:41:36 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>
#include <cerrno>
#include <cfloat>

static bool isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "nanf" ||
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff");
}

static bool isCharLiteral(const std::string& str) {
    return (str.length() == 3 && str.front() == '\'' && str.back() == '\'');
}

static bool isSingleChar(const std::string& str) {
    return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

static void printChar(double val) {
    if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(val)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

static void printInt(double val) {
    if (std::isnan(val) || std::isinf(val) || 
        val < static_cast<double>(std::numeric_limits<int>::min()) ||
        val > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

static void printFloat(double val) {
    if (std::isnan(val))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(val)) {
        if (val > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    else {
        float f = static_cast<float>(val);
        if (f == static_cast<int>(f) && f >= -1000000 && f <= 1000000)
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }
}

static void printDouble(double val) {
    if (std::isnan(val))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(val)) {
        if (val > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
    else {
        if (val == static_cast<int>(val) && val >= -1000000 && val <= 1000000)
            std::cout << "double: " << val << ".0" << std::endl;
        else
            std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    double value = 0.0;

    if (isCharLiteral(literal)) {
        value = static_cast<double>(literal[1]);
    }
    else if (isSingleChar(literal)) {
        value = static_cast<double>(literal[0]);
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
        errno = 0;
        char* end;
        value = std::strtod(literal.c_str(), &end);

        bool validFormat = (end == literal.c_str() + literal.size()) ||
                           (end == literal.c_str() + literal.size() - 1 && *end == 'f');

        if (end == literal.c_str() || !validFormat) {
            std::cout << "Error: invalid literal." << std::endl;
            return;
        }

        if (errno == ERANGE) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}
