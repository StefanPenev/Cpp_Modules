/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:54:22 by stefan            #+#    #+#             */
/*   Updated: 2025/05/03 17:54:24 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    Data original;
    original.number = 42;
    original.text = "Hello, world!";

    std::cout << "Original Data address: " << &original << std::endl;
    std::cout << "Original Data content: " << original.number << ", " << original.text << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Deserialized Data address: " << deserialized << std::endl;
    std::cout << "Deserialized Data content: " << deserialized->number << ", " << deserialized->text << std::endl;

    if (deserialized == &original)
        std::cout << "Success: Deserialized pointer matches original!" << std::endl;
    else
        std::cout << "Error: Pointers do not match." << std::endl;

    return 0;
}
