/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:05:12 by stefan            #+#    #+#             */
/*   Updated: 2025/03/19 10:07:30 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

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

    // Constructor & Destructor
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Member functions
    void incrementGrade();
    void decrementGrade();

    // Overloaded operator
    friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
};

#endif
