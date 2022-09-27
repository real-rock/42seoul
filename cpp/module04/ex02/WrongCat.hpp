/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 07:56:21 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/27 10:27:07 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_H
#define WRONG_CAT_H

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat(const std::string &type_in);
    WrongCat(const WrongCat &d);
    ~WrongCat();

    WrongCat &operator=(const WrongCat &d);
    void makeSound() const;
};

#endif