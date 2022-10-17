/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:30:28 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/17 11:39:54 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _max(n) {}

Span::~Span() {
    _clear();
}

void Span::_copy(const Span &s) {
    _clear();
    _data = s._data;
    _max = s._max;
}

void Span::_clear() {
    _data.clear();
}

Span::Span(const Span &s) {
    _copy(s);
}

Span &Span::operator=(const Span &s) {
    _copy(s);
    return *this;
}

void Span::addNumber(int n) {
    if (_data.size() + 1 > _max)
        throw ContainerFullException();
    _data.insert(n);
}

unsigned int Span::shortestSpan() const {
    if (_data.size() == 0 || _data.size() == 1)
        throw SpanException();

    long long old;
    long long res = std::numeric_limits<unsigned int>::max();

    old = *_data.begin();
    for (std::set<int>::iterator it = _data.begin(); it != _data.end(); it++) {
        if (it == _data.begin())
            continue;
        long long tmp = *it - old;
        if (tmp < res)
            res = tmp;
        old = *it;
    }
    return static_cast<unsigned int>(res);
}

unsigned int Span::longestSpan() const {
    if (_data.size() == 0 || _data.size() == 1)
        throw SpanException();

    std::set<int>::iterator first = _data.begin();
    std::set<int>::iterator last = _data.end();

    long long tmp = static_cast<long long>(*(--last)) - static_cast<long long>(*first);

    return static_cast<unsigned int>(tmp);
}

void Span::print() const {
    for (std::set<int>::iterator it = _data.begin(); it != _data.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
