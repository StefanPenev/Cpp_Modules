/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:04:52 by stefan            #+#    #+#             */
/*   Updated: 2025/05/03 15:06:03 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 42);
        Form formA("TaxForm", 50, 30);

        std::cout << bob << std::endl;
        std::cout << formA << std::endl;

        bob.signForm(formA);
        std::cout << formA << std::endl;

        Bureaucrat lowRank("Jim", 100);
        Form formB("TopSecret", 20, 10);

        std::cout << lowRank << std::endl;
        std::cout << formB << std::endl;

        lowRank.signForm(formB); // Should fail

    } catch (std::exception& e) {
        std::cerr << "Unhandled Exception: " << e.what() << std::endl;
    }

    return 0;
}

