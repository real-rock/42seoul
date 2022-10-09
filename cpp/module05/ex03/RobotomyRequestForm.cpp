/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:34:48 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/07 14:29:52 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("", max_grade_for_sign, max_grade_for_exec) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &s) : Form(s, max_grade_for_sign, max_grade_for_exec) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f) : Form(f) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (!getSigned())
        throw NotSignedException();
    if (getGradeForExec() < executor.getGrade())
        throw GradeForExecTooLowException();
    std::cout << getName() << " has been robotomized successfully 50% of the time" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &f) {
    std::cout << "Can't copy anything" << std::endl;
    f.getName();
    return *this;
}
