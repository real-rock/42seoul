/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:12:07 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/23 08:55:48 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(const std::string &type_in): Animal(type_in) {}

Cat::Cat(const Cat &d) {
    _copy(d);
}

Cat &Cat::operator=(const Cat &d) {
    _copy(d);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meowwwwww" << std::endl;
}
