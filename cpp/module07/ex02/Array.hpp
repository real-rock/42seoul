/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:02:05 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/16 12:05:17 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

template <class T>
class Array {
private:
    T *_data;
    unsigned int _len;

    void _data_init(unsigned int n);
    void _copy(const Array<T> &a);
    void _clear();

public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &a);
    ~Array();

    unsigned int size() const;
    void *getPtr() const;

    Array &operator=(const Array<T> &a);
    T &operator[](unsigned int n);
};

template <class T>
Array<T>::Array() {
    _data_init(0);
    _len = 0;
}

template <class T>
Array<T>::Array(unsigned int n) {
    _data_init(n);
    _len = n;
}

template <class T>
Array<T>::Array(const Array<T> &a) {
    _copy(a);
}

template <class T>
Array<T>::~Array() {
    _clear();
}

template <class T>
unsigned int Array<T>::size() const {
    return _len;
}

template <class T>
void *Array<T>::getPtr() const {
    return static_cast<void *>(_data);
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &a) {
    _copy(a);
    return *this;
}

template <class T>
T &Array<T>::operator[](unsigned int n) {
    if (size() <= n || n < 0)
        throw std::out_of_range("Index is out of range.");
    return _data[n];
}

template <class T>
void Array<T>::_data_init(unsigned int n) {
    _data = new T[n];
}

template <class T>
void Array<T>::_clear() {
    if (_data != nullptr)
        delete[] _data;
    _data = nullptr;
}

template <class T>
void Array<T>::_copy(const Array<T> &a) {
    _clear();
    _data_init(a.size());

    _len = a.size();
    for (unsigned int i = 0; i < a.size(); i++)
        _data[i] = a._data[i];
}

#endif