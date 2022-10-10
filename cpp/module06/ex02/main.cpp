/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:23:47 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/10 17:21:32 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    const int max = 3;
    srand(time(nullptr));

    int r = rand() % max;
    switch (r) {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    default:
        break;
    }
    return nullptr;
}

void identify(Base* p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify2(Base& p) {
    try {
        A &a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        a.~A();
    } catch (std::exception &e) {}

    try {
        B &b = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        b.~B();
    } catch (std::exception &e) {}

    try {
        C &c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        c.~C();
    } catch (std::exception &e) {}
}

int main() {
    Base *tmp = generate();

    identify(tmp);
    identify2(*tmp);
    delete tmp;
}
