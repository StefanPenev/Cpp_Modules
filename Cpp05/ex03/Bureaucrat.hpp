/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:52:05 by stefan            #+#    #+#             */
/*   Updated: 2025/05/04 13:11:10 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;  // forward declaration to avoid circular include

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    // Constructors and destructor
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);               
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Member functions
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& form) const;
    void executeForm(const AForm& form) const;

    // Operator overload
    friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
};

#endif
