/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:53:25 by stefan            #+#    #+#             */
/*   Updated: 2025/07/24 12:28:26 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _storage;

public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template<typename InputIterator>
    void addRange(InputIterator begin, InputIterator end) {
        if (_storage.size() + std::distance(begin, end) > _maxSize)
            throw std::runtime_error("Span overflow: too many numbers in range");
        _storage.insert(_storage.end(), begin, end);
    }
};

#endif
