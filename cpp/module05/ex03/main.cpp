/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:42:35 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/07 14:42:50 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
    Intern i;
    Form *s;
    Bureaucrat b("BBBBB", 45);

    try {
        s = i.makeForm("shrubbery creation", "sss");
        std::cout << *s << std::endl;
        try {
            b.signForm(*s);
            b.executeForm(*s);
            std::cout << b << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        delete s;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        s = i.makeForm("robotomy request", "rrr");
        std::cout << *s << std::endl;
        try {
            b.signForm(*s);
            b.executeForm(*s);
            std::cout << b << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        delete s;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        s = i.makeForm("presidential pardon", "ppp");
        std::cout << *s << std::endl;
        try {
            b.signForm(*s);
            b.executeForm(*s);
            std::cout << b << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        delete s;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        s = i.makeForm("no", "ppp");
        std::cout << *s << std::endl;
        try {
            b.signForm(*s);
            b.executeForm(*s);
            std::cout << b << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        delete s;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
