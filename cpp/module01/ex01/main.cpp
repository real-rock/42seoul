/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:14:39 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/13 14:36:53 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie *zombies;

    zombies = zombieHorde(5, "zombie1");
    for (int i = 0; i < 5; i++) {
        zombies[i].announce();
    }
    delete[] zombies;
}
