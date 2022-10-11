/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:25:18 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/11 17:36:51 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    unsigned int s = 10;
    Array<int> a(s);

    for (int i = 0; i < 10; i++) {
        a[i] = i * 2;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    Array<int> b(0);
    std::cout << "b size: " << b.size() << " b ptr: " << b.getPtr() << std::endl;

    try {
        std::cout << b[0] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Array<float> c(10);
}
