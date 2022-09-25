/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 06:44:48 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/23 10:21:43 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
    Brain *_brain;

public:
    Dog(const std::string &type_in);
    Dog(const Dog &d);
    ~Dog();

    Dog &operator=(const Dog &d);
    virtual void makeSound() const;
    void setIdea(int idx, const std::string s);
    void print(int idx) const;
};

#endif