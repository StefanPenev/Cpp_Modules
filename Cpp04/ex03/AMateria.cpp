/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:43:47 by stefan            #+#    #+#             */
/*   Updated: 2025/03/14 11:58:16 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructor
AMateria::AMateria(std::string const & type) : type(type) {}

// Getter for the type
std::string const & AMateria::getType() const {
    return this->type;
}

// Virtual use method, to be overridden by derived classes
void AMateria::use(ICharacter& target) {
    (void)target; // To avoid unused parameter warning, this is a base class implementation
}
