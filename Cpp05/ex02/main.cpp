/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:59:09 by stefan            #+#    #+#             */
/*   Updated: 2025/05/04 12:59:10 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat high("HighRank", 1);
        Bureaucrat mid("MidRank", 45);
        Bureaucrat low("LowRank", 150);

        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n--- Signing Forms ---\n";
        high.signForm(shrub);
        high.signForm(robo);
        high.signForm(pardon);

        std::cout << "\n--- Executing Forms ---\n";
        high.executeForm(shrub);
        high.executeForm(robo);
        high.executeForm(pardon);

        std::cout << "\n--- Failure Tests ---\n";

        // Fail to sign due to low grade
        try {
            low.signForm(shrub);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Fail to execute unsigned form
        try {
            ShrubberyCreationForm badForm("Nowhere");
            high.executeForm(badForm); // Not signed
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Fail to execute due to insufficient grade
        try {
            mid.executeForm(pardon); // MidRank (45) too low to exec PPF (5)
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }

    return 0;
}
