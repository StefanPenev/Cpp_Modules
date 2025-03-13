/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:31:58 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 10:32:00 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
    *this = other;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = other.ideas[i];
    }
    std::cout << "Brain assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    return (index >= 0 && index < 100) ? ideas[index] : "";
}