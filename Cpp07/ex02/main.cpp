/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:09:04 by stefan            #+#    #+#             */
/*   Updated: 2025/05/04 14:20:51 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> intArray(5);
        for (size_t i = 0; i < intArray.size(); ++i)
            intArray[i] = static_cast<int>(i) * 2;

        std::cout << "intArray contents:" << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i)
            std::cout << intArray[i] << std::endl;

        Array<int> copiedArray = intArray;
        copiedArray[0] = 100;

        std::cout << "Original after copy modified:" << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i)
            std::cout << intArray[i] << std::endl;

        std::cout << "Copied array:" << std::endl;
        for (size_t i = 0; i < copiedArray.size(); ++i)
            std::cout << copiedArray[i] << std::endl;

        std::cout << "Accessing out of bounds:" << std::endl;
        std::cout << intArray[10] << std::endl; // This will throw
    } catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
