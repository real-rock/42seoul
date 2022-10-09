/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:13:26 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/07 14:33:06 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void Bureaucrat::_copy(const Bureaucrat& b) {
    setGrade(b._grade);
}

Bureaucrat::Bureaucrat(const std::string& s, int g) : _name(s) {
    setGrade(g);
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b._name) {
    setGrade(b.getGrade());
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

void Bureaucrat::signForm(Form &f) const {
    try {
        f.beSigned(*this);
    } catch (Form::AlreadySignedException &ae) {
        std::cout << getName() << " couldn't sign " << f.getName() << std::endl;
        return;
    } catch (std::exception &e) {
        std::cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
        return;
    }
    std::cout << getName() << " signed " << f.getName() << std::endl;
}

void Bureaucrat::executeForm(const Form &f) {
    try {
        f.execute(*this);
    } catch (std::exception &e) {
        std::cout << getName() << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
        return;
    }
    std::cout << getName() << " executed " << f.getName() << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
    _copy(b);
    return *this;
}

void Bureaucrat::decrement(int q) {
    if ((long long)_grade + q > min_grade)
        throw GradeTooLowException();
    _grade += q;
}

void Bureaucrat::increment(int q) {
    if ((long long)_grade - q < max_grade)
        throw GradeTooHighException();
    _grade -= q;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
