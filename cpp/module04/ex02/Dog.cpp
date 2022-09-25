/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:11:53 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/23 10:22:21 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(const std::string &type_in): AAnimal(type_in) {
    _brain = new Brain;
    std::cout << type_in << " borned with new brain" << std::endl;
}

Dog::Dog(const Dog &d) {
    _brain = new Brain;
    *this = d;
}

Dog &Dog::operator=(const Dog &d) {
    _copy(d);
    *_brain = *d._brain;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog died and delete brain" << std::endl;
    delete _brain;
}

void Dog::makeSound() const {
    std::cout << "Woof woof!" << std::endl;
}

void Dog::setIdea(int idx, const std::string s) {
    _brain->setIdea(idx, s);
}

void Dog::print(int idx) const {
    std::cout << "Idea address: " << (void *)_brain->getIdeas() << std::endl;
    std::cout << "Element in idx: " << _brain->getIdeas()[idx] << std::endl;
}
