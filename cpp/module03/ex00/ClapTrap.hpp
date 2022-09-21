/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:46:48 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 17:25:19 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>
#include <string>

class ClapTrap {
private:
    std::string _name;
    int _hitPoint;
    int _energyPoint;
    int _attackDamage;

public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &ct);
    ~ClapTrap();

    const std::string &getName() const;
    int getAttackDamage() const;
    void setAttackDamage(int damage);

    void print() const;
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    bool is_alive() const;
    ClapTrap &operator=(const ClapTrap &c);
};

#endif