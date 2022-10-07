/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:30:21 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/07 14:30:53 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _signed(false), _grade_s(min_grade), _grade_e(min_grade) {}

Form::Form(const std::string &s, int g_s, int g_e) : _name(s), _signed(false), _grade_s(g_s), _grade_e(g_e) {
    if (g_s < max_grade || g_e < max_grade)
        throw GradeTooHighException();
    else if (g_s > min_grade || g_e > min_grade)
        throw GradeTooLowException();
}

Form::Form(const Form &f) : _name(f.getName()), _signed(f.getSigned()), _grade_s(f.getGradeForSign()), _grade_e(f.getGradeForExec()) {}

Form::~Form() {}

std::string Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getGradeForSign() const {
    return _grade_s;
}

int Form::getGradeForExec() const {
    return _grade_e;
}

void Form::beSigned(const Bureaucrat &b) {
    if (_signed)
        throw AlreadySignedException();
    if (_grade_s < b.getGrade())
        throw GradeForSignTooLowException();
    _signed = true;
}

Form& Form::operator=(const Form &f) {
    _signed = f.getSigned();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Name: " << f.getName() << ", Signed: " << f.getSigned() << \
        ", Grade for sign: " << f.getGradeForSign() << ", Grade for exec: " << f.getGradeForExec();
    return os;
}
