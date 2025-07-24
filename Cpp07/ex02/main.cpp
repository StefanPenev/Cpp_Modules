/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:09:04 by stefan            #+#    #+#             */
/*   Updated: 2025/07/24 11:28:06 by spenev           ###   ########.fr       */
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

// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }