/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:30:21 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 17:45:47 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name(""), _signed(false), _grade_s(Bureaucrat::min_grade), _grade_e(Bureaucrat::min_grade) {}

Form::Form(const std::string &s, int g_s, int g_e): _name(s), _signed(false), _grade_s(g_s), _grade_e(g_e) {}

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
    if (_signed) {
        std::cout << b.getName() << " couldn't sign " << _name << " because already signed" << std::endl;
    }
    if (_grade_s < b.getGrade())
        throw GradeTooLowException();
    std::cout << b.getName() << " signed " << _name << std::endl;
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
