/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:13:26 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 17:12:24 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int Bureaucrat::max_grade = 1;
int Bureaucrat::min_grade = 150;

void Bureaucrat::_copy(const Bureaucrat& b) {
    setGrade(b._grade);
}

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

void Bureaucrat::signForm(Form &f) const {
    try {
        f.beSigned(*this);
    } catch (Form::GradeTooLowException &ge) {
        std::cout << getName() << " couldn't sign " << f.getName() << " because grade is too low" << std::endl;
    } catch (Form::AlreadySignedException &ae) {
        std::cout << getName() << " couldn't sign " << f.getName() << " because already signed" << std::endl;
    } catch (std::exception &e) {
        std::cout << getName() << " couldn't sign " << f.getName() << " because something went wrong" << std::endl;
    }
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
