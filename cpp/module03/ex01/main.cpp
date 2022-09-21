/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:37:52 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 17:42:31 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    ClapTrap c("ctA");
    ScavTrap s("stA");

    c.setAttackDamage(3);
    c.print();
    s.print();
    s.guardGate();
    while (c.is_alive() || s.is_alive()) {
        if (c.is_alive() && s.is_alive()) {
            c.attack(s.getName());
            s.takeDamage(c.getAttackDamage());
        }
        if (c.is_alive() && s.is_alive()) {
            s.attack(c.getName());
            c.takeDamage(s.getAttackDamage());
        }
        if (c.is_alive())
            c.beRepaired(3);
        if (s.is_alive())
            s.beRepaired(1);
        c.print();
        s.print();
    }
}