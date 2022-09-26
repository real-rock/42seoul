/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 07:56:21 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/26 07:59:40 by jiheo            ###   ########.fr       */
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
    // virtual void makeSound() const;
};

#endif