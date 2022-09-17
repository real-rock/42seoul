/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:49:47 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/16 17:08:24 by jiheo            ###   ########.fr       */
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
    friend std::ostream& operator<<(std::ostream& os, const Fixed& f);
};

#endif