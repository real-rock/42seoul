/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:50:15 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/16 12:02:37 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void func(int x) {
    std::cout << "iteration function x: " << x << std::endl;
}

template <class T>
void func2(T x) {
    std::cout << "iteration function x: " << x << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    char cs[] = {'a', 'b', 'c', 'd', 'e'};

    iter(arr, 8, func);
    iter(cs, 5, func2);
}
