/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:46:10 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/11 16:50:08 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

template <class T>
void iter(T *arr, unsigned int len, void (*f)(T)) {
    for (unsigned int i = 0; i < len; i++) {
        f(arr[i]);
    }
}

#endif