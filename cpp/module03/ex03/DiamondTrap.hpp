/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:55:53 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 20:23:45 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string _name;

public:
    DiamondTrap(const std::string& name);
    virtual ~DiamondTrap();

    void attack(const std::string &target);
};

DiamondTrap::DiamondTrap(const std::string& name) : \
    ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name") {
    std::cout << "Diamond constructor called" << std::endl;
    _name = name;
    _hitPoint = FragTrap::_hitPoint;
    _energyPoint = ScavTrap::_energyPoint;
    _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "Diamond destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

#endif