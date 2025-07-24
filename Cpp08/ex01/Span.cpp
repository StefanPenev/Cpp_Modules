/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:53:35 by stefan            #+#    #+#             */
/*   Updated: 2025/07/24 12:28:23 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other)
    : _maxSize(other._maxSize), _storage(other._storage) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _storage = other._storage;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_storage.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _storage.push_back(number);
}

int Span::shortestSpan() const {
    if (_storage.size() < 2)
        throw std::runtime_error("Not enough elements for a span");

    std::vector<int> sorted(_storage);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (std::size_t i = 2; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_storage.size() < 2)
        throw std::runtime_error("Not enough elements for a span");

    int min = *std::min_element(_storage.begin(), _storage.end());
    int max = *std::max_element(_storage.begin(), _storage.end());

    return max - min;
}
