/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:44:25 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 13:44:27 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

// Constructor (sets type to "cure")
Cure::Cure() : AMateria("cure") {}

// Destructor
Cure::~Cure() {}

// Clone method to create a new Cure object
AMateria* Cure::clone() const {
    return new Cure(*this);
}

// Use method to print the healing message
void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
