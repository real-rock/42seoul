/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:55:10 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 18:34:46 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include "Form.hpp"

class RobotomyRequestForm: virtual public Form {
private:
    static const int max_grade_for_sign = 72;
    static const int max_grade_for_exec = 45;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &s);
    RobotomyRequestForm(const RobotomyRequestForm &f);
    ~RobotomyRequestForm();

    virtual void execute(const Bureaucrat &executor) const;
    RobotomyRequestForm& operator=(const RobotomyRequestForm &f);
};

#endif