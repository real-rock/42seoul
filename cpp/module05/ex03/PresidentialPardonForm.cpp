/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:34:34 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 18:34:41 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("", max_grade_for_sign, max_grade_for_exec) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &s) : Form(s, max_grade_for_sign, max_grade_for_exec) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &f) : Form(f) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (!isExecutable(executor))
        throw NotExecutableException();
    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &f) {
    std::cout << "Can't copy anything" << std::endl;
    f.getName();
    return *this;
}
