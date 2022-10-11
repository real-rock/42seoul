/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:50:15 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/11 16:51:29 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void function(int x) {
    std::cout << "iteration function x: " << x << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    iter(arr, 8, function);
}
