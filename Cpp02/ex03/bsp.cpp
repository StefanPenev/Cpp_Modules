/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:05:05 by stefan            #+#    #+#             */
/*   Updated: 2025/03/12 10:33:33 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c) {
    return Fixed(0.5f * std::abs((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
                                  b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
                                  c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);
    return (A == A1 + A2 + A3);
}