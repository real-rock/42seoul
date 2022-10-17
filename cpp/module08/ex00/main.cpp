/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:49:49 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/17 10:54:21 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec1(10);

    for (int i = 0; i < 10; i++) {
        vec1[i] = i * 2;
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    try {
        easyfind(vec1, 4);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        easyfind(vec1, 5);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::list<int> lst1;
    for (int i = 0; i < 10; i++) {
        lst1.push_back(i * 3);
        std::cout << (i * 3) << " ";
    }
    std::cout << std::endl;
    try {
        easyfind(lst1, 6);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        easyfind(lst1, 8);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}
