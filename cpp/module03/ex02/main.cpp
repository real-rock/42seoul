/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:43:17 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 17:52:14 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap s("stA");
    FragTrap f("ftA");

    f.print();
    s.print();
    s.guardGate();
    f.highFivesGuys();
    while (f.is_alive() || s.is_alive()) {
        if (f.is_alive() && s.is_alive()) {
            f.attack(s.getName());
            s.takeDamage(f.getAttackDamage());
        }
        if (f.is_alive() && s.is_alive()) {
            s.attack(f.getName());
            f.takeDamage(s.getAttackDamage());
        }
        if (f.is_alive())
            f.beRepaired(3);
        if (s.is_alive())
            s.beRepaired(1);
        f.print();
        s.print();
    }
}