/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:03:01 by stefan            #+#    #+#             */
/*   Updated: 2025/05/04 14:03:58 by stefan           ###   ########.fr       */
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
void increment(T &element) {
    ++element;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    std::string strArr[] = {"hello", "world", "iter", "template"};

    std::cout << "Original int array:" << std::endl;
    iter(intArr, 5, printElement);

    iter(intArr, 5, increment);

    std::cout << "Incremented int array:" << std::endl;
    iter(intArr, 5, printElement);

    std::cout << "String array:" << std::endl;
    iter(strArr, 4, printElement);

    return 0;
}
