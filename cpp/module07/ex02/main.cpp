/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:25:18 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/16 12:11:37 by jiheo            ###   ########.fr       */
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

    std::cout << std::endl;

    try {
        std::cout << b[0] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << b[-1] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    Array<float> c(10);
    for (int i = 0; i < 10; i++) {
        c[i] = i * 2 + 0.3;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    Array<int> cp(a);
    std::cout << "a pointer: " << a.getPtr() << " copied pointer: " << cp.getPtr() << std::endl;
    std::cout << "a" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "copied" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << cp[i] << " ";
    }
    std::cout << std::endl;
}
