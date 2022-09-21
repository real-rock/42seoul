/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:32:17 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 20:20:51 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &st);
    virtual ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
    ScavTrap &operator=(const ScavTrap &st);
};

#endif