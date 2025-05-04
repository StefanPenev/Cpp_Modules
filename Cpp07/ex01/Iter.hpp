/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:02:08 by stefan            #+#    #+#             */
/*   Updated: 2025/05/04 14:05:09 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
    if (!array || !func)
        return;
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif
