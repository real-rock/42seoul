/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:44:58 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/21 20:20:46 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &ft);
    virtual ~FragTrap();

    void attack(const std::string &target);
    void highFivesGuys();
    FragTrap &operator=(const FragTrap &ft);
};

#endif