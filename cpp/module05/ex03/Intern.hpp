/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:29:54 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/07 14:39:31 by jiheo            ###   ########.fr       */
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
    class InvalidFormNameException : public std::exception {
    public:
        const char* what() const throw () { return "couldn't find name you entered."; }
    };

    Intern();
    Intern(const Intern& i);
    ~Intern();

    Form* makeForm(const std::string& form_name, const std::string& target) const;
    Intern& operator=(const Intern& i);
};

std::ostream& operator<<(std::ostream& os, const Intern& i);

#endif