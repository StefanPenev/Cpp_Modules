/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:04:26 by stefan            #+#    #+#             */
/*   Updated: 2025/03/12 10:32:15 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {}
Fixed::Fixed(const int value) { _fixedPointValue = value << _fractionalBits; }
Fixed::Fixed(const float value) { _fixedPointValue = roundf(value * (1 << _fractionalBits)); }
Fixed::Fixed(const Fixed &other) { *this = other; }
Fixed &Fixed::operator=(const Fixed &other) { if (this != &other) _fixedPointValue = other.getRawBits(); return *this; }
Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return _fixedPointValue; }
void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }
float Fixed::toFloat(void) const { return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits); }
int Fixed::toInt(void) const { return _fixedPointValue >> _fractionalBits; }

bool Fixed::operator>(const Fixed &other) const { return _fixedPointValue > other._fixedPointValue; }
bool Fixed::operator<(const Fixed &other) const { return _fixedPointValue < other._fixedPointValue; }
bool Fixed::operator>=(const Fixed &other) const { return _fixedPointValue >= other._fixedPointValue; }
bool Fixed::operator<=(const Fixed &other) const { return _fixedPointValue <= other._fixedPointValue; }
bool Fixed::operator==(const Fixed &other) const { return _fixedPointValue == other._fixedPointValue; }
bool Fixed::operator!=(const Fixed &other) const { return _fixedPointValue != other._fixedPointValue; }

Fixed Fixed::operator+(const Fixed &other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { return Fixed(this->toFloat() / other.toFloat()); }

Fixed &Fixed::operator++() { _fixedPointValue++; return *this; }
Fixed Fixed::operator++(int) { Fixed temp = *this; ++(*this); return temp; }
Fixed &Fixed::operator--() { _fixedPointValue--; return *this; }
Fixed Fixed::operator--(int) { Fixed temp = *this; --(*this); return temp; }

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) { out << fixed.toFloat(); return out; }