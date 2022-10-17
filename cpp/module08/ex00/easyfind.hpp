/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:40:40 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/17 10:54:36 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_H
#define EASY_FIND_H

#include <iostream>
#include <algorithm>
#include <stdexcept>

class ItemNotFoundException : public std::exception {
    const char* what() const throw () {
        return "Item not found.";
    }
};


template<class T>
void easyfind(const T& v, int t) {
    if (std::find(v.begin(), v.end(), t) == v.end()) {
        throw ItemNotFoundException();
    }
    std::cout << "Item " << t << " found in the container." << std::endl;
}

#endif