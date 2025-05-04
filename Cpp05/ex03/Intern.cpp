/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:16:37 by stefan            #+#    #+#             */
/*   Updated: 2025/05/04 13:16:47 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    struct FormPair {
        const char* name;
        AForm* (*create)(const std::string& target);
    };

    FormPair forms[] = {
        { "shrubbery creation", [](const std::string& t) -> AForm* { return new ShrubberyCreationForm(t); } },
        { "robotomy request", [](const std::string& t) -> AForm* { return new RobotomyRequestForm(t); } },
        { "presidential pardon", [](const std::string& t) -> AForm* { return new PresidentialPardonForm(t); } }
    };

    for (size_t i = 0; i < sizeof(forms)/sizeof(forms[0]); ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    std::cerr << "Intern: Unknown form name \"" << formName << "\"" << std::endl;
    return nullptr;
}
