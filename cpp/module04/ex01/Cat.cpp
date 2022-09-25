/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:12:07 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/23 08:55:48 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(const std::string &type_in): Animal(type_in) {
    _brain = new Brain;
    std::cout << type_in << " borned with new brain" << std::endl;
}

Cat::Cat(const Cat &d) {
    _brain = new Brain;
    *this = d;
}

Cat &Cat::operator=(const Cat &d) {
    _copy(d);
    *_brain = *d._brain;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat died and delete brain" << std::endl;
    delete _brain;
}

void Cat::makeSound() const {
    std::cout << "Meowwwwww" << std::endl;
}

void Cat::setIdea(int idx, const std::string s) {
    _brain->setIdea(idx, s);
}

void Cat::print(int idx) const {
    std::cout << "Idea address: " << (void *)_brain->getIdeas() << std::endl;
    std::cout << "Element in idx: " << _brain->getIdeas()[idx] << std::endl;
}
