/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:41:36 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/16 11:59:07 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

template <class T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
T &min(T &a, T &b) {
    if (a < b)
        return a;
    else
        return b;
}

template <class T>
T &max(T &a, T &b) {
    if (a > b)
        return a;
    else
        return b;
}

#endif