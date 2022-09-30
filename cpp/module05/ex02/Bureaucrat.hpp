/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:13:30 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 17:30:10 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "Form.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

    void _copy(const Bureaucrat& b);

public:
    static int max_grade;
    static int min_grade;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw () { return "Too high grade value. Grade must be in between 1 to 150"; }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw () { return "Too low grade value. Grade must be in between 1 to 150"; }
    };

    Bureaucrat(const std::string& s, int g);
    Bureaucrat(const Bureaucrat& b);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void setGrade(int grade);
    void decrement(int q);
    void increment(int q);
    void signForm(Form &f) const;
    void executeForm(const Form &f);

    Bureaucrat& operator=(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif