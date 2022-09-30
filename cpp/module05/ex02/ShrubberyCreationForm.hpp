/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:56:21 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 18:34:58 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm: virtual public Form {
private:
    static const int max_grade_for_sign = 145;
    static const int max_grade_for_exec = 137;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &s);
    ShrubberyCreationForm(const ShrubberyCreationForm &f);
    ~ShrubberyCreationForm();

    virtual void execute(const Bureaucrat &executor) const;
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &f);
};

#endif