/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:42:15 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/17 12:15:11 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H
#define MUTANT_STACK_H

#include <stack>

template <class T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }

public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack<T> &ms);
    MutantStack &operator=(const MutantStack<T> &ms);
};

template <class T>
MutantStack<T>::MutantStack() {}

template <class T>
MutantStack<T>::~MutantStack() {}

template <class T>
MutantStack<T>::MutantStack(const MutantStack<T> &ms) {
    *this = ms;
}

template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &ms) {
    (void)ms;
    return *this;
}

#endif