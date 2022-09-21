/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:46:48 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 20:22:30 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>
#include <string>

class ClapTrap {
protected:
    std::string _name;
    int _hitPoint;
    int _energyPoint;
    int _attackDamage;

    void _copy(const ClapTrap &ct);

public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &ct);
    ~ClapTrap();

    const std::string &getName() const;
    int getAttackDamage() const;
    void setAttackDamage(int damage);

    void print() const;
    virtual void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    bool is_alive() const;
    ClapTrap &operator=(const ClapTrap &c);
};

#endif