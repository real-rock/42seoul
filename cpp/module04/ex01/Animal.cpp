/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 06:44:14 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/23 08:55:48 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(const std::string &type_in) {
    _type = type_in;
}

Animal::Animal(const Animal &a) {
    _copy(a);
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &a) {
    _copy(a);
    return *this;
}

void Animal::_copy(const Animal &a) {
    _type = a._type;
}

void Animal::makeSound() const {}

std::string Animal::getType() const {
    return _type;
}
