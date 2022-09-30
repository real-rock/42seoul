/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:42:35 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 18:36:37 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    Bureaucrat b("bur", 45);
    ShrubberyCreationForm sf("shrubbery");
    RobotomyRequestForm rf("robotomy");
    PresidentialPardonForm pf("presidential");

    try {
        b.signForm(sf);
        b.executeForm(sf);
        std::cout << b << std::endl;
        std::cout << sf << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b.signForm(rf);
        b.executeForm(rf);
        std::cout << b << std::endl;
        std::cout << rf << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b.signForm(pf);
        b.executeForm(pf);
        std::cout << b << std::endl;
        std::cout << pf << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
