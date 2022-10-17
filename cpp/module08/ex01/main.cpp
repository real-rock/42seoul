/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:30:43 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/17 11:41:30 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    Span s(1000000);

    for (int i = 0; i < 1000000; i++) {
        s.addNumber(i);
    }

    try {
        s.addNumber(1000);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl; // this line must be executed
    }

    // s.print();

    std::cout << s.longestSpan() << std::endl; // must be 99999
    std::cout << s.shortestSpan() << std::endl; // must be 1

    Span c(1000);
    c.addNumber(std::numeric_limits<int>::max());
    c.addNumber(std::numeric_limits<int>::min());
    c.addNumber(0);
    std::cout << c.longestSpan() << std::endl; // must be 4294967295
    std::cout << c.shortestSpan() << std::endl; // must be 2147483647

    Span d(0);
    try {
        d.addNumber(1000);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl; // this line must be executed
    }

    try {
        std::cout << d.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl; // this line must be executed
    }

    try {
        std::cout << d.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl; // this line must be executed
    }
}
