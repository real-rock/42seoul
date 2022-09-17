/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:15:03 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/16 16:47:31 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::_frac_bit = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called\n";
    _n = 0;
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

Fixed &Fixed::operator=(const Fixed &cp) {
    std::cout << "Copy assignment operator called\n";
    _n = cp.getRawBits();
    return *this;
}
