/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:11:47 by stefan            #+#    #+#             */
/*   Updated: 2025/02/28 11:55:45 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Colors.hpp"

bool isOnlyDigits(const std::string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

void getValidatedPhoneNumber(std::string& field) {
    do {
        std::cout << GREEN << "Enter Phone Number: " << RESET;
        std::getline(std::cin, field);

        if (field.empty()) {
            std::cout << RED << "Error: Field cannot be empty. Try again.\n" << RESET;
        } else if (!isOnlyDigits(field)) {
            std::cout << RED << "Error: Phone number must contain only digits. Try again.\n" << RESET;
            field.clear();  // Clear invalid input
        }
    } while (field.empty() || !isOnlyDigits(field));
}

void getValidatedInput(const std::string& prompt, std::string& field) {
    do {
        std::cout <<GREEN<< prompt<<RESET;
        std::getline(std::cin, field);
        if (field.empty()) 
            std::cout <<RED<< "Error: Field cannot be empty. Try again.\n"<<RESET;
    } while (field.empty());
}

void Contact::setContactDetails() {
    getValidatedInput("Enter First Name: ", firstName);
    getValidatedInput("Enter Last Name: ", lastName);
    getValidatedInput("Enter Nickname: ", nickname);
    getValidatedPhoneNumber(phoneNumber);
    getValidatedInput("Enter Darkest Secret: ", darkestSecret);
    
    std::cout << YELLOW << "Contact saved successfully!\n" << RESET;
}

void Contact::displayShort(int index) const {
    std::cout << "|" << std::setw(10) << index << "|";
    std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|";
    std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|";
    std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|";
    std::cout << std::endl;
}

void Contact::displayFull() const {
    std::cout << GREEN << "First Name: " << firstName << "\n" << RESET;
    std::cout << GREEN <<"Last Name: " << lastName << "\n" << RESET;
    std::cout << GREEN <<"Nickname: " << nickname << "\n" << RESET;
    std::cout << GREEN <<"Phone Number: " << phoneNumber << "\n" << RESET;
    std::cout << GREEN <<"Darkest Secret: " << darkestSecret << "\n" << RESET;
}

bool Contact::isEmpty() const {
    return firstName.empty();
}
