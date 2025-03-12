/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:05:24 by stefan            #+#    #+#             */
/*   Updated: 2025/03/12 10:33:18 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {}
Point::Point(const Point &other) : x(other.x), y(other.y) {}
Point &Point::operator=(const Point &other) { (void)other; return *this; }
Point::~Point() {}
Fixed Point::getX() const { return x; }
Fixed Point::getY() const { return y; }