/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:12:16 by spenev            #+#    #+#             */
/*   Updated: 2025/08/07 13:12:17 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);

    static void validateAndBenchmarkSort(int argc, char** argv);

private:
    static void checkInput(int argc, char** argv);

    static void fordJohnsonSortVector(std::vector<unsigned int>& container);
    static void fordJohnsonSortDeque(std::deque<unsigned int>& container);

    static void insertionSortVector(std::vector<unsigned int>& container, size_t left, size_t right);
    static void insertionSortDeque(std::deque<unsigned int>& container, size_t left, size_t right);

    static std::vector<size_t> generateJacobsthalIndices(size_t n);

    static std::vector<unsigned int>::iterator binaryInsertVector(
        std::vector<unsigned int>& container,
        unsigned int value,
        size_t left,
        size_t right);

    static std::deque<unsigned int>::iterator binaryInsertDeque(
        std::deque<unsigned int>& container,
        unsigned int value,
        size_t left,
        size_t right);

    template<typename Container>
    static void printContainer(const std::string& label, const Container& container) {
        std::cout << label;
        for (typename Container::size_type i = 0; i < container.size(); ++i) {
            std::cout << " " << container[i];
        }
        std::cout << std::endl;
    }
};

#endif