/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:49:12 by stefan            #+#    #+#             */
/*   Updated: 2025/05/04 13:07:44 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
        target = other.target;
    return *this;
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream ofs(target + "_shrubbery");
    if (ofs.is_open()) {
        ofs << "       _-_\n"
               "    /~~   ~~\\\n"
               " /~~         ~~\\\n"
               "{               }\n"
               " \\  _-     -_  /\n"
               "   ~  \\\\ //  ~\n"
               "_- -   | | _- _\n"
               "  _ -  | |   -_\n"
               "      // \\\\\n";
        ofs.close();
    }
}

