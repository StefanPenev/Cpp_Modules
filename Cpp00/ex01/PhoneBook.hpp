/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:12:31 by stefan            #+#    #+#             */
/*   Updated: 2025/02/28 09:12:33 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook {
private:
    Contact contacts[8];
    int contactIndex;
    int totalContacts;

public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
    void displayMenu() const;
};

#endif
