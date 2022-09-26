/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 07:58:41 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/26 07:59:33 by jiheo            ###   ########.fr       */
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
