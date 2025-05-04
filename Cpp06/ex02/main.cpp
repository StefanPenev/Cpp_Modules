/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:20:09 by stefan            #+#    #+#             */
/*   Updated: 2025/05/04 12:20:11 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>

int main() {
    Base* ptr = generate();

    std::cout << "Identification by pointer: ";
    identify(ptr);

    std::cout << "Identification by reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}
