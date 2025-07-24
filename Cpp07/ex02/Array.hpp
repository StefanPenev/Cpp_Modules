/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:09:11 by stefan            #+#    #+#             */
/*   Updated: 2025/07/24 11:14:26 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](size_t index);
    const T &operator[](size_t index) const;

    size_t size() const;

private:
    T *data_;
    size_t size_;
};

#include "Array.tpp"

#endif 
