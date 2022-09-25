/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 06:52:08 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/23 10:21:35 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain *_brain;

public:
    Cat(const std::string &type_in);
    Cat(const Cat &d);
    ~Cat();

    Cat &operator=(const Cat &d);
    
    virtual void makeSound() const;
    void setIdea(int idx, const std::string s);
    void print(int idx) const;
};

#endif