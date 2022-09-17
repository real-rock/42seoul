/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:50:55 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/13 15:43:51 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon {
private:
    std::string _type;

public:
    Weapon(std::string type_in);
    ~Weapon();
    const std::string& getType() const;
    void setType(const std::string &type_in);
};

#endif