/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:39:33 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/13 14:13:18 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
private:
    std::string _name;
public:
    Zombie(std::string name_in);
    ~Zombie();
    void announce() const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif