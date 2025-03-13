/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:23:18 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 13:09:35 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void abstractClassTest() {
    std::cout << "=== Abstract Class Test ===" << std::endl;

    // AAnimal* test = new AAnimal(); // This should NOT compile!

    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << "Dog is of type: " << dog->getType() << std::endl;
    std::cout << "Cat is of type: " << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "========================" << std::endl;
}

int main() {
    abstractClassTest();
    return 0;
}