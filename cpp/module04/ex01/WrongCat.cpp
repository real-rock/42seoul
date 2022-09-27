/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 07:58:41 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/27 12:52:18 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(const std::string &type_in): WrongAnimal(type_in) {}

WrongCat::WrongCat(const WrongCat &d) {
    _copy(d);
}

WrongCat &WrongCat::operator=(const WrongCat &d) {
    _copy(d);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong cat sound" << std::endl;
}
