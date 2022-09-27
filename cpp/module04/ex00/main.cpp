/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 06:38:51 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/27 10:26:20 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    // const Animal *meta = new Animal("animal1");
    // const Animal *j = new Dog("dog");
    // const Animal *i = new Cat("cat");

    // std::cout << meta->getType() << " " << std::endl;
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;

    // j->makeSound();
    // i->makeSound();

    // delete i;
    // delete j;
    // delete meta;

    const WrongAnimal *meta = new WrongAnimal("animal1");
    const WrongAnimal *i = new WrongCat("cat");

    std::cout << meta->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();

    delete i;
    delete meta;
}
