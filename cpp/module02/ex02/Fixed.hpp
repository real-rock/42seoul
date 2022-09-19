/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:31:05 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/19 10:36:10 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
    static int _frac_bit;
    int _n;

public:
    static const Fixed &min(const Fixed &f1, const Fixed &f2);
    static Fixed &min(Fixed &f1, Fixed &f2);
    static const Fixed &max(const Fixed &f1, const Fixed &f2);
    static Fixed &max(Fixed &f1, Fixed &f2);
    
    Fixed();
    Fixed(int n_in);
    Fixed(float n_in);
    Fixed(const Fixed &cp);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(const int n_in);
    float toFloat() const;
    int toInt() const;

    Fixed &operator=(const Fixed &cp);
    Fixed operator+(const Fixed &f);
    Fixed operator-(const Fixed &f);
    Fixed operator*(const Fixed &f);
    Fixed operator/(const Fixed &f);

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    bool operator==(const Fixed &f) const;
    bool operator!=(const Fixed &f) const;
    bool operator<(const Fixed &f) const;
    bool operator>(const Fixed &f) const;
    bool operator<=(const Fixed &f) const;
    bool operator>=(const Fixed &f) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif