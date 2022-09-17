/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:48:47 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/16 16:47:28 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
    static int _frac_bit;
    int _n;

public:
    Fixed();
    Fixed(const Fixed &cp);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(const int n_in);

    Fixed &operator=(const Fixed &cp);
};

#endif