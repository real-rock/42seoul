/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:44:13 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 20:21:36 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
    std::cout << "Scav constructor called" << std::endl;
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "Scav destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st): ClapTrap(st._name) {
    ClapTrap::_copy(st);
}

void ScavTrap::attack(const std::string &target) {
    if (!is_alive())
        return;
    std::cout << "ScavTrap " << _name << " attacks " << target << \
        ", causing " << _attackDamage << " points of damage!\n";
    _energyPoint--;
}

void ScavTrap::guardGate() {
    std::cout << "Scav is now in Gate keeper mode" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st) {
    ClapTrap::_copy(st);
    return *this;
}
