/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:55:34 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/17 19:21:52 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <stdexcept>
#include <set>
#include <limits>

class Span {
public:
    class ContainerFullException : public std::exception {
        const char* what() const throw () {
            return "Failed to add number, container is full already.";
        }
    };
    class SpanException : public std::exception {
        const char* what() const throw () {
            return "Container only contains 1 or 0 items, couldn't get span from this container.";
        }
    };

private:
    std::multiset<int> _data;
    unsigned int _max;

    void _copy(const Span &s);
    void _clear();

public:
    Span(unsigned int n);
    ~Span();
    Span(const Span &s);

    void addNumber(int n);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    void print() const;

    Span &operator=(const Span &s);
};

#endif