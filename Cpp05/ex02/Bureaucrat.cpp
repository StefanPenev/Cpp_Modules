/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:52:43 by stefan            #+#    #+#             */
/*   Updated: 2025/05/04 13:10:08 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

// Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade = other.grade; // name is const
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getters
const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

// Grade modifications
void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    ++grade;
}

// Exception messages
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

// Form interaction: signing
void Bureaucrat::signForm(AForm& form) const {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

// Form interaction: executing
void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

// Operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
