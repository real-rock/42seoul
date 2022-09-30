/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:53:27 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 19:33:36 by jiheo            ###   ########.fr       */
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

public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw () { return "Too high grade value. Grade must be in between 1 to 150"; }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw () { return "Too low grade value. Grade must be in between 1 to 150"; }
    };
    class AlreadySignedException : public std::exception {
    public:
        const char* what() const throw () { return "Already signed."; }
    };
    class NotExecutableException : public std::exception {
    public:
        const char* what() const throw () { return "Not executable form."; }
    };
    Form();
    Form(const std::string& s, int g_s, int g_e);
    Form(const Form& f);
    virtual ~Form();

    std::string getName() const;
    bool getSigned() const;
    int getGradeForSign() const;
    int getGradeForExec() const;

    void beSigned(const Bureaucrat& b);
    bool isExecutable(const Bureaucrat& executor) const;

    virtual void execute(const Bureaucrat& executor) const = 0;

    Form& operator=(const Form& f);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif