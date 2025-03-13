/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:23:18 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 10:35:38 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    Animal* animals[4];
    for (int i = 0; i < 2; ++i) animals[i] = new Dog();
    for (int i = 2; i < 4; ++i) animals[i] = new Cat();

    for (int i = 0; i < 4; ++i) {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i) delete animals[i];

    // Deep copy test
    Dog a;
    a.makeSound();
    Dog b(a);
    b.makeSound();

    return 0;
}
