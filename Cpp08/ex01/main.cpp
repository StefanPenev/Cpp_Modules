/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:53:19 by stefan            #+#    #+#             */
/*   Updated: 2025/05/05 08:54:47 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        Span largeSpan(10000);
        std::srand(std::time(0));
        std::vector<int> vec;
        for (int i = 0; i < 10000; ++i)
            vec.push_back(std::rand());

        largeSpan.addRange(vec.begin(), vec.end());
        std::cout << "Large span test:\n";
        std::cout << "Shortest: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest: " << largeSpan.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
