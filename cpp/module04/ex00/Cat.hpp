/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 06:52:08 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/27 10:25:25 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat(const std::string &type_in);
    Cat(const Cat &d);
    virtual ~Cat();

    Cat &operator=(const Cat &d);
    virtual void makeSound() const;
};

#endif