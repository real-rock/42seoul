/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:36:40 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/10 15:15:47 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

void print_data(Data *d) {
    std::cout << "name: " << d->name << std::endl;
    std::cout << "age: " << d->age << std::endl;
    std::cout << "weights: " << d->weights << std::endl;
    std::cout << "heights: " << d->heights << std::endl;
}

int main() {
    Data d;

    d.name = "jiheo";
    d.age = 26;
    d.weights = 77;
    d.heights = 173;
    print_data(&d);

    uintptr_t ptr = serialize(&d);
    Data *dd = deserialize(ptr);
    print_data(dd);
}
