/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:30:56 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/20 12:37:45 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::_frac_bit = 8;

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
    if (f1 < f2)
        return f1;
    else
        return f2;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
    if (f1 < f2)
        return f1;
    else
        return f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
    if (f1 < f2)
        return f2;
    else
        return f1;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
    if (f1 < f2)
        return f2;
    else
        return f1;
}

Fixed::Fixed() {
    _n = 0;
}

Fixed::Fixed(int n_in) {
    _n = n_in << Fixed::_frac_bit;
}

Fixed::Fixed(float n_in) {
    _n = roundf(n_in * (1 << Fixed::_frac_bit));
}

Fixed::Fixed(const Fixed& cp) {
    *this = cp;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
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

Fixed& Fixed::operator=(const Fixed& cp) {
    _n = cp.getRawBits();
    return *this;
}

Fixed Fixed::operator+(const Fixed& f) {
    Fixed new_f(*this);

    new_f.setRawBits(this->getRawBits() + f.getRawBits());
    return new_f;
}

Fixed Fixed::operator-(const Fixed& f) {
    Fixed new_f(*this);

    new_f.setRawBits(this->getRawBits() - f.getRawBits());
    return new_f;
}

Fixed Fixed::operator*(const Fixed& f) {
    Fixed new_f(*this);
    long long tmp = (long long)this->getRawBits() * (long long)f.getRawBits();

    new_f.setRawBits((tmp / (1 << Fixed::_frac_bit)));
    return new_f;
}

Fixed Fixed::operator/(const Fixed& f) {
    Fixed new_f(*this);

    int tmp = this->getRawBits() / f.getRawBits();
    new_f.setRawBits(tmp << Fixed::_frac_bit);
    return new_f;
}

Fixed& Fixed::operator++() {
    _n++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed new_f(*this);
    operator++();
    return new_f;
}

Fixed& Fixed::operator--() {
    _n--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed new_f(*this);
    operator--();
    return new_f;
}


bool Fixed::operator==(const Fixed& f) const {
    return this->getRawBits() == f.getRawBits();
}

bool Fixed::operator!=(const Fixed& f) const {
    return  this->getRawBits() != f.getRawBits();
}

bool Fixed::operator<(const Fixed& f) const {
    return this->getRawBits() < f.getRawBits();
}

bool Fixed::operator>(const Fixed& f) const {
    return this->getRawBits() > f.getRawBits();
}

bool Fixed::operator<=(const Fixed& f) const {
    return  this->getRawBits() <= f.getRawBits();
}

bool Fixed::operator>=(const Fixed& f) const {
    return  this->getRawBits() >= f.getRawBits();
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
