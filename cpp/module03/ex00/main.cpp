/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:46:43 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 17:29:28 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap a("ctA"), b("ctB");

    a.setAttackDamage(3);
    b.setAttackDamage(5);
    a.print();
    b.print();
    while (a.is_alive() || b.is_alive()) {
        if (a.is_alive() && b.is_alive()) {
            a.attack(b.getName());
            b.takeDamage(a.getAttackDamage());
        }
        if (a.is_alive() && b.is_alive()) {
            b.attack(a.getName());
            a.takeDamage(b.getAttackDamage());
        }
        if (a.is_alive())
            a.beRepaired(3);
        if (b.is_alive())
            b.beRepaired(1);
        a.print();
        b.print();
    }
}
