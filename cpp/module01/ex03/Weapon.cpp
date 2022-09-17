/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:56:15 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/13 15:43:48 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type_in) {
    setType(type_in);
}

Weapon::~Weapon() {}

const std::string &Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string &type_in) {
    _type = type_in;
}
