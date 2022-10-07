/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:42:35 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/07 13:40:57 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat b("bur", 15);
    std::cout << b << std::endl;
    try {
        Bureaucrat c("cur", 15151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    b.setGrade(30);
    while (true) {
        try {
            b.decrement(1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            break;
        }
        std::cout << b << std::endl;
    }
    b.setGrade(50);
    while (true) {
        try {
            b.increment(1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            break;
        }
        std::cout << b << std::endl;
    }
}
