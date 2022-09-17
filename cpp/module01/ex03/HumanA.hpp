/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:56:45 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/13 15:43:14 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
#define HUMAN_A_H

#include "Weapon.hpp"

class HumanA {
private:
    std::string _name;
    Weapon *_weapon;

public:
    HumanA(std::string name_in, Weapon &weapon_in);
    ~HumanA();
    void attack() const;
};

HumanA::HumanA(std::string name_in, Weapon &weapon_in) {
    _name = name_in;
    _weapon = &weapon_in;
}

HumanA::~HumanA() {}

void HumanA::attack() const {
    std::cout << _name << " attacks with their " << _weapon->getType() << '\n';
}

#endif