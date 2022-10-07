/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:36:21 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/07 14:39:40 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Form* Intern::createShrubberyCreationForm(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}

Form* Intern::createRobotomyRequestForm(const std::string &target) const {
    return new RobotomyRequestForm(target);
}

Form* Intern::createPresidentialPardonForm(const std::string &target) const {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern::~Intern() {}

Form* Intern::makeForm(const std::string& form_name, const std::string& target) const {
    static Form* (Intern::*_funcs[FORM_SIZE])(const std::string &t) const = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

    static std::string names[FORM_SIZE] = {
        "shrubbery creation", "robotomy request", "presidential pardon"
    };
    for (int i = 0; i < FORM_SIZE; i++) {
        if (form_name == names[i]) {
            Form* (Intern::*func)(const std::string &t) const = _funcs[i];
            std::cout << "Intern creates " << form_name << std::endl;
            return (this->*func)(target);
        }
    }
    throw InvalidFormNameException();
}

Intern& Intern::operator=(const Intern&) {
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Intern&) {
    os << "Just an intern";
    return os;
}
