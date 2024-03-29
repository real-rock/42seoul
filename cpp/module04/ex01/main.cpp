/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:24:35 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/26 08:07:44 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    // Animal construction test
    Animal *animals[10];
    for (int i = 0; i < 10; i++) {
        std::cout << "Excution: " << i << std::endl;
        if (i % 2 == 0) {
            animals[i] = new Cat(std::string("Cat"));
        }
        else {
            animals[i] = new Dog(std::string("Dog"));
        }
    }

    // Animal destruction test
    for (int i = 0; i < 10; i++) {
        delete animals[i];
    }

    // Copy test
    Cat a("catA");
    Cat b(a);

    a.setIdea(0, "This is aaaaa");
    b.setIdea(0, "This is bbbbb");

    b.print(0);
    a.print(0);

    Cat c("catC");
    c = a;
}
