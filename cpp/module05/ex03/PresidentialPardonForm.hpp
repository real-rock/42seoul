/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:34:34 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 18:34:33 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include "Form.hpp"

class PresidentialPardonForm: virtual public Form {
private:
    static const int max_grade_for_sign = 25;
    static const int max_grade_for_exec = 5;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &s);
    PresidentialPardonForm(const PresidentialPardonForm &f);
    ~PresidentialPardonForm();

    virtual void execute(const Bureaucrat &executor) const;
    PresidentialPardonForm& operator=(const PresidentialPardonForm &f);
};

#endif