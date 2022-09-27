/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 07:57:35 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/27 12:52:08 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(const std::string &type_in) {
    _type = type_in;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a) {
    _copy(a);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a) {
    _copy(a);
    return *this;
}

void WrongAnimal::_copy(const WrongAnimal &a) {
    _type = a._type;
}

void WrongAnimal::makeSound() const {
    std::cout << "What animal sound?" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}
