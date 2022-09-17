/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:57:04 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/13 15:42:25 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"

class HumanB {
private:
    std::string _name;
    Weapon *_weapon;

public:
    HumanB(std::string name_in);
    ~HumanB();
    void setWeapon(Weapon &weapon_in);
    void attack() const;
};

HumanB::HumanB(std::string name_in) {
    _name = name_in;
    _weapon = nullptr;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon_in) {
    //_weapon = weapon_in;
    //_weapon.setType(weapon_in.getType());
    _weapon = &weapon_in;
}

void HumanB::attack() const {
    if (_weapon == nullptr)
        std::cout << _name << " attacks with their fist\n";
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << '\n';
}

#endif