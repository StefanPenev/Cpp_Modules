/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:42:11 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 09:42:14 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
    *this = other;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other)
        this->type = other.type;
    std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Some generic animal sound..." << std::endl;
}
