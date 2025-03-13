/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:43:18 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 10:32:57 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow meow!" << std::endl;
}
