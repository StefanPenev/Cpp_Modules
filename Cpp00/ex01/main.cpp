/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:13:22 by stefan            #+#    #+#             */
/*   Updated: 2025/02/28 11:36:22 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Colors.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout <<BLUE<< "Enter a command (ADD, SEARCH, EXIT): "<<RESET;
        std::getline(std::cin, command);

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } else if (command == "EXIT") {
            std::cout <<YELLOW<< "Exiting phonebook.\n"<<RESET;
            break;
        } else {
            std::cout <<RED<< "Invalid command. Try again.\n"<<RESET;
        }
    }
    return 0;
}
