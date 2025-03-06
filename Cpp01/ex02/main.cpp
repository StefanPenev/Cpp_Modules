/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:22:02 by stefan            #+#    #+#             */
/*   Updated: 2025/03/06 14:25:50 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
    std::string brain = "HI THIS IS BRAIN";

    // Pointer to the string
    std::string* stringPTR = &brain;

    // Reference to the string
    std::string& stringREF = brain;

    // Memory addresses
    std::cout << "Memory address of the string variable: " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR:     " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:     " << &stringREF << std::endl;

    // Print values
    std::cout << "\nValue of the string variable:      " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR:     " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF:     " << stringREF << std::endl;

    return 0;
}