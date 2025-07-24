/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:48:11 by stefan            #+#    #+#             */
/*   Updated: 2025/07/24 12:28:12 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        std::vector<int>::iterator itVec = easyfind(vec, 20);
        std::cout << "Found in vector: " << *itVec << std::endl;

        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(15);
        lst.push_back(25);

        std::list<int>::iterator itList = easyfind(lst, 100); // Will throw
        std::cout << "Found in list: " << *itList << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
