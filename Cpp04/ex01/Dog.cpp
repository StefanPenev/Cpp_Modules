/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:42:37 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 10:33:34 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof woof!" << std::endl;
}
