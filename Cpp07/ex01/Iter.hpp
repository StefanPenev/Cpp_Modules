/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:02:08 by stefan            #+#    #+#             */
/*   Updated: 2025/06/30 12:12:27 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename Func>
void iterImpl(T *array, size_t length, Func func) {
    if (!array || !func)
        return;
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
    iterImpl(array, length, func);
}

template <typename T>
void iter(const T *array, size_t length, void (*func)(const T &)) {
    iterImpl(array, length, func);
}

#endif
