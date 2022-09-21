/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:09:02 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 17:30:13 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name): _name(name) {
    _hitPoint = 10;
    _energyPoint = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &ct) {
    *this = ct;
}

ClapTrap::~ClapTrap() {}

const std::string &ClapTrap::getName() const {
    return _name;
}

int ClapTrap::getAttackDamage() const {
    if (is_alive())
        return _attackDamage;
    else
        return 0;
}

void ClapTrap::setAttackDamage(int damage) {
    _attackDamage = damage;
}

void ClapTrap::print() const {
    std::cout << "====== " << _name << " ======" << std::endl;
    if (is_alive()) {
        std::cout << "Hit point: " << _hitPoint << std::endl;
        std::cout << "Energy point: " << _energyPoint << std::endl;
        std::cout << "Attack damage: " << _attackDamage << std::endl;
    }
    else {
        std::cout << "DEAD" << std::endl;
    }
}

bool ClapTrap::is_alive() const {
    return _energyPoint > 0 && _hitPoint > 0;
}

void ClapTrap::attack(const std::string &target) {
    if (!is_alive())
        return;
    std::cout << "ClapTrap " << _name << " attacks " << target << \
        ", causing " << _attackDamage << " points of damage!\n";
    _energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (!is_alive())
        return;
    _hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!is_alive())
        return;
    _hitPoint += amount;
    _energyPoint--;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c) {
    _name = c._name;
    _hitPoint = c._hitPoint;
    _energyPoint = c._energyPoint;
    _attackDamage = c._attackDamage;
    return *this;
}
