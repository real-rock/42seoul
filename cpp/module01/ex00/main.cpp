/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:14:39 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/13 14:17:48 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::string names[5] = {
        "Zombie1", "Zombie2", "Zombie3", "Zombie4", "Zombie5"
    };

    for (int i = 0; i < 5; i++) {
        randomChump(names[i]);
    }
}
