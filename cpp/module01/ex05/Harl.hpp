/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:46:17 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/14 16:29:56 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>

#define MAX_SIZE 4

class Harl {
private:
    void debug();
    void info();
    void warning();
    void error();

public:
    Harl();
    ~Harl();
    void complain(std::string level_in);
};

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level_in) {
    static void	(Harl::*_funcs[MAX_SIZE])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
    static std::string levels[MAX_SIZE] = {
        "debug", "info", "warning", "error"
    };
    for (int i = 0; i < MAX_SIZE; i++) {
        if (level_in == levels[i]) {
            void (Harl::*func)() = _funcs[i];
            (this->*func)();
            return;
        }
    }
}

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do\n";
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

#endif