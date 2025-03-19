/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSOurce.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:45:22 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 13:45:24 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// Constructor initializes the materia array to nullptr
MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        materia[i] = nullptr;
    }
}

// Copy constructor
MateriaSource::MateriaSource(MateriaSource const & src) {
    for (int i = 0; i < 4; ++i) {
        if (src.materia[i]) {
            materia[i] = src.materia[i]->clone();
        } else {
            materia[i] = nullptr;
        }
    }
}

// Copy assignment operator
MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; ++i) {
            delete materia[i];  // Free existing materia
            if (rhs.materia[i]) {
                materia[i] = rhs.materia[i]->clone();
            } else {
                materia[i] = nullptr;
            }
        }
    }
    return *this;
}

// Destructor (delete the materia)
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete materia[i];
    }
}

// Learn a new Materia
void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!materia[i]) {
            materia[i] = m;
            break;
        }
    }
}

// Create a new Materia from a type string
AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (materia[i] && materia[i]->getType() == type) {
            return materia[i]->clone();
        }
    }
    return nullptr;  // Return nullptr if the type is unknown
}
