/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:03:01 by stefan            #+#    #+#             */
/*   Updated: 2025/06/30 12:15:11 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Iter.hpp"

template <typename T>
void printElement(T &element) {
    std::cout << element << std::endl;
}

template <typename T>
void printConstElement(const T &element) {
    std::cout << element << std::endl;
}

template <typename T>
void increment(T &element) {
    ++element;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    std::string strArr[] = {"hello", "world", "iter", "template"};

    std::cout << "Original int array:" << std::endl;
    iter(intArr, 5, printElement);
    std::cout << std::endl;

    iter(intArr, 5, increment);

    std::cout << "Incremented int array:" << std::endl;
    iter(intArr, 5, printElement);
    std::cout << std::endl;

    std::cout << "String array:" << std::endl;
    iter(strArr, 4, printElement);
    std::cout << std::endl;

    const int constIntArr[] = {10, 20, 30};
    std::cout << "Const int array:" << std::endl;
    iter(constIntArr, 3, printConstElement);
    std::cout << std::endl;

    const double doubleArr[] = {3.14, 2.718, 1.618};
    std::cout << "Const double array:" << std::endl;
    iter(doubleArr, 3, printConstElement);
    std::cout << std::endl;

    return 0;
}
