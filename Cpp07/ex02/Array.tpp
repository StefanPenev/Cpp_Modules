/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:10:01 by stefan            #+#    #+#             */
/*   Updated: 2025/07/24 11:14:31 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : data_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data_(new T[n]()), size_(n) {}

template <typename T>
Array<T>::Array(const Array &other) : data_(NULL), size_(0) {
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = new T[size_];
        for (size_t i = 0; i < size_; ++i)
            data_[i] = other.data_[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data_;
}

template <typename T>
T &Array<T>::operator[](size_t index) {
    if (index >= size_)
        throw std::out_of_range("Index out of bounds");
    return data_[index];
}

template <typename T>
const T &Array<T>::operator[](size_t index) const {
    if (index >= size_)
        throw std::out_of_range("Index out of bounds");
    return data_[index];
}

template <typename T>
size_t Array<T>::size() const {
    return size_;
}

#endif 
