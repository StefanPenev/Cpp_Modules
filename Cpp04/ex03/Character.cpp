/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:44:56 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 13:44:58 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

// Constructor
Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; ++i) {
        inventory[i] = nullptr;  // Initialize inventory to nullptr
    }
}

// Copy constructor (deep copy)
Character::Character(Character const & src) : name(src.name) {
    for (int i = 0; i < 4; ++i) {
        if (src.inventory[i]) {
            inventory[i] = src.inventory[i]->clone();
        } else {
            inventory[i] = nullptr;
        }
    }
}

// Copy assignment operator (deep copy)
Character & Character::operator=(Character const & rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];  // Free existing inventory
            if (rhs.inventory[i]) {
                inventory[i] = rhs.inventory[i]->clone();
            } else {
                inventory[i] = nullptr;
            }
        }
        this->name = rhs.name;
    }
    return *this;
}

// Destructor (delete the inventory)
Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
}

// Getter for the name
std::string const & Character::getName() const {
    return this->name;
}

// Equip a Materia to the inventory
void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            break;
        }
    }
}

// Unequip a Materia from the inventory (without deleting it)
void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx] = nullptr;
    }
}

// Use a Materia in the inventory
void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}
