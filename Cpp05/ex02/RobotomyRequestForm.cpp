/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:50:20 by stefan            #+#    #+#             */
/*   Updated: 2025/05/04 13:08:20 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
        target = other.target;
    return *this;
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "Bzzzz... Drilling noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "." << std::endl;
}
