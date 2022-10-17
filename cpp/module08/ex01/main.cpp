/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:30:43 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/17 19:22:25 by jiheo            ###   ########.fr       */
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
    
    Span e(5);
    e.addNumber(3);
    e.addNumber(3);
    e.addNumber(1);
    e.addNumber(5);
    std::cout << e.shortestSpan() << std::endl;
}

/*
MutantStack class
There is a MutantStack class that inherits from std::stack and offers
all of its member functions.
It has an iterator. Also, it is possible to do at least the operations
shown in the subject's examples using iterators.

Class and member functions
There is a class that complies with the requirements of the subject.
Its member functions use STL algorithms to find their result as much as
possible. Finding the shortest span can't be done only by subtracting
the two lowest numbers (take a closer look at the subject example).

Improved addNumber function
There's a way to add numbers that's more practical than calling the
addNumber() function repeatedly.
*/
