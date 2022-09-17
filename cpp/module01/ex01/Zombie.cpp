/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:11:41 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/13 14:26:33 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
    std::cout << "Zombie name '" << _name << "' dead\n";
}

void Zombie::setName(std::string name_in) {
    _name = name_in;
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
