/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 06:44:14 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/23 10:21:24 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {}

AAnimal::AAnimal(const std::string &type_in) {
    _type = type_in;
}

AAnimal::AAnimal(const AAnimal &a) {
    _copy(a);
}

AAnimal::~AAnimal() {
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &a) {
    _copy(a);
    return *this;
}

void AAnimal::_copy(const AAnimal &a) {
    _type = a._type;
}

std::string AAnimal::getType() const {
    return _type;
}
