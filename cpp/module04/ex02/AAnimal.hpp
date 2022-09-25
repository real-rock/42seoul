/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 06:39:47 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/23 10:20:28 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAIL_H
#define ANIMAIL_H

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string _type;
    void _copy(const AAnimal &a);

public:
    AAnimal();
    AAnimal(const std::string &type_in);
    AAnimal(const AAnimal &a);
    virtual ~AAnimal();
    AAnimal &operator=(const AAnimal &a);

    std::string getType() const;
    virtual void makeSound() const = 0;
};

#endif