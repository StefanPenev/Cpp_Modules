/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:12:59 by stefan            #+#    #+#             */
/*   Updated: 2025/02/28 11:53:38 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Colors.hpp"

PhoneBook::PhoneBook() : contactIndex(0), totalContacts(0) {}

void PhoneBook::addContact() {
    std::cout <<YELLOW<< "Adding a new contact...\n"<<RESET;
    contacts[contactIndex].setContactDetails();

    if (!contacts[contactIndex].isEmpty()) {
        contactIndex = (contactIndex + 1) % 8;
        if (totalContacts < 8) totalContacts++;
    }
}

bool isValidIndex(const std::string& input, int& index, int maxContacts) {
    if (input.empty()) return false;

    std::stringstream ss(input);
    if (!(ss >> index) || index < 0 || index >= maxContacts) return false;

    return true;
}

int getValidatedIndex(int maxContacts) {
    std::string input;
    int index;

    do {
        std::cout << YELLOW << "Enter index to display: " << RESET;
        std::getline(std::cin, input);

        if (!isValidIndex(input, index, maxContacts)) {
            std::cout << RED << "Invalid input! Please enter a valid index.\n" << RESET;
        }
    } while (!isValidIndex(input, index, maxContacts));

    return index;
}

void PhoneBook::searchContacts() const {
    if (totalContacts == 0) {
        std::cout << RED << "Phonebook is empty!\n" << RESET;
        return;
    }

    std::cout << "|----------|----------|----------|----------|\n";
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    std::cout << "|----------|----------|----------|----------|\n";
    
    for (int i = 0; i < totalContacts; i++) {
        contacts[i].displayShort(i);
    }
    std::cout << "|----------|----------|----------|----------|\n";

    int index = getValidatedIndex(totalContacts);
    contacts[index].displayFull();
}

void PhoneBook::displayMenu() const {
    std::cout <<BLUE<< "Available commands: ADD, SEARCH, EXIT\n"<<RESET;
}
