/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 06:39:47 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/23 08:55:51 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAIL_H
#define ANIMAIL_H

#include <iostream>
#include <string>

class Animal {
protected:
    std::string _type;
    void _copy(const Animal &a);

public:
    Animal();
    Animal(const std::string &type_in);
    Animal(const Animal &a);
    virtual ~Animal();
    Animal &operator=(const Animal &a);

    std::string getType() const;
    virtual void makeSound() const;
};

#endif