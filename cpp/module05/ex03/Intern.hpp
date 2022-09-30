/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:29:54 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 20:18:42 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define FORM_SIZE 3

class Intern {
private:
    Form* createShrubberyCreationForm(const std::string &target) const;
    Form* createRobotomyRequestForm(const std::string &target) const;
    Form* createPresidentialPardonForm(const std::string &target) const;

public:
    Intern();
    Intern(const Intern& i);
    ~Intern();

    Form* makeForm(const std::string& form_name, const std::string& target) const;
    Intern& operator=(const Intern& i);
};

std::ostream& operator<<(std::ostream& os, const Intern& i);

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
    std::cout << "Invalid form name" << std::endl;
    return nullptr;
}

Intern& Intern::operator=(const Intern&) {
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Intern&) {
    os << "Just an intern";
    return os;
}

#endif