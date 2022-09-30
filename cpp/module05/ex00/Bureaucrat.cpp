/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:13:26 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 16:31:21 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int Bureaucrat::max_grade = 1;
int Bureaucrat::min_grade = 150;

void Bureaucrat::_copy(const Bureaucrat& b) {
    setGrade(b._grade);
}

Bureaucrat::Bureaucrat(): _name(""), _grade(min_grade) {}

Bureaucrat::Bureaucrat(const std::string& s, int g) : _name(s), _grade(g) {}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b._name) {
    _grade = b._grade;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::setGrade(int grade) {
    if (grade < max_grade)
        throw GradeTooHighException();
    else if (grade > min_grade)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
    _copy(b);
    return *this;
}

Bureaucrat& Bureaucrat::operator++() {
    if (_grade == max_grade)
        throw GradeTooHighException();
    _grade--;
    return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
    Bureaucrat new_b(*this);
    operator++();
    return new_b;
}

Bureaucrat& Bureaucrat::operator--() {
    if (_grade == min_grade)
        throw GradeTooLowException();
    _grade++;
    return *this;
}

Bureaucrat Bureaucrat::operator--(int) {
    Bureaucrat new_b(*this);
    operator--();
    return new_b;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
