/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:44:11 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 13:44:13 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

// Constructor (sets type to "ice")
Ice::Ice() : AMateria("ice") {}

// Destructor
Ice::~Ice() {}

// Clone method to create a new Ice object
AMateria* Ice::clone() const {
    return new Ice(*this);
}

// Use method to print the ice bolt message
void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
