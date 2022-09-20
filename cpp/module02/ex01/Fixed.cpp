/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:49:59 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/20 12:36:22 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::_frac_bit = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called\n";
    _n = 0;
}

Fixed::Fixed(int n_in) {
    std::cout << "Int constructor called\n";
    _n = n_in << Fixed::_frac_bit;
}

Fixed::Fixed(float n_in) {
    std::cout << "Float constructor called\n";
    _n = roundf(n_in * (1 << Fixed::_frac_bit));
}

Fixed::Fixed(const Fixed &cp) {
    std::cout << "Copy constructor called\n";
    *this = cp;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return _n;
}

void Fixed::setRawBits(const int n_in) {
    _n = n_in;
}

float Fixed::toFloat() const {
    return (float)_n / (float)(1 << Fixed::_frac_bit);
}

int Fixed::toInt() const {
    return _n >> Fixed::_frac_bit;
}

Fixed &Fixed::operator=(const Fixed &cp) {
    std::cout << "Copy assignment operator called\n";
    _n = cp.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return os;
}
