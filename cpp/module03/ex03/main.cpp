/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:43:17 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 20:27:26 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    DiamondTrap da("dtA"), db("dtB");

    da.print();
    db.print();
    da.guardGate();
    da.highFivesGuys();
    db.guardGate();
    db.highFivesGuys();
    while (da.is_alive() || db.is_alive()) {
        if (da.is_alive() && db.is_alive()) {
            db.attack(da.getName());
            da.takeDamage(db.getAttackDamage());
        }
        if (da.is_alive() && db.is_alive()) {
            da.attack(db.getName());
            db.takeDamage(da.getAttackDamage());
        }
        if (da.is_alive())
            da.beRepaired(2);
        if (db.is_alive())
            db.beRepaired(3);
        da.print();
        db.print();
    }
}