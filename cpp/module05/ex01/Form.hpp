/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:53:27 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/07 14:19:23 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _signed;
    const int _grade_s;
    const int _grade_e;

    const static int max_grade = 1;
    const static int min_grade = 150;

public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw () { return "Too high grade value. Grade must be in between 1 to 150"; }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw () { return "Too low grade value. Grade must be in between 1 to 150"; }
    };
    class GradeForSignTooLowException : public std::exception {
    public:
        const char* what() const throw () { return "grade for sign is too low."; }
    };
    class GradeForExecTooLowException : public std::exception {
    public:
        const char* what() const throw () { return "grade for execute is too low."; }
    };
    class AlreadySignedException : public std::exception {
    public:
        const char* what() const throw () { return "already signed"; }
    };
    Form();
    Form(const std::string &s, int g_s, int g_e);
    Form(const Form &f);
    ~Form();

    std::string getName() const;
    void setGradeForSign(int grade);
    void setGradeForExec(int grade);
    bool getSigned() const;
    int getGradeForSign() const;
    int getGradeForExec() const;

    void beSigned(const Bureaucrat &b);

    Form& operator=(const Form &f);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif