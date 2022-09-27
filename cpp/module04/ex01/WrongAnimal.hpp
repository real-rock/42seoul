/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 07:56:06 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/27 12:52:11 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string _type;
    void _copy(const WrongAnimal &a);

public:
    WrongAnimal();
    WrongAnimal(const std::string &type_in);
    WrongAnimal(const WrongAnimal &a);
    ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &a);

    std::string getType() const;
    void makeSound() const;
};

#endif