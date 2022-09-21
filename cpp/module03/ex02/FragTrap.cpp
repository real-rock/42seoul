/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:48:35 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 20:19:37 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
    std::cout << "Frag constructor called" << std::endl;
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "Frag destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ft): ClapTrap(ft._name) {
    ClapTrap::_copy(ft);
}

FragTrap &FragTrap::operator=(const FragTrap &ft) {
    ClapTrap::_copy(ft);
    return *this;
}

void FragTrap::attack(const std::string &target) {
    if (!is_alive())
        return;
    std::cout << "FragTrap " << _name << " attacks " << target << \
        ", causing " << _attackDamage << " points of damage!\n";
    _energyPoint--;
}

void FragTrap::highFivesGuys() {
    std::cout << "Let's high fives guys!" << std::endl;
}
