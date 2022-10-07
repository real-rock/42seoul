/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:42:35 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/07 14:23:44 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat b("bur", 15);
    std::cout << b << std::endl;
    try {
        Form f("invForm", 15151, 14);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // b.setGrade(3);

    Form f("fName", 25, 10);
    std::cout << f << std::endl;
    b.signForm(f);
    b.signForm(f);

    Form f2("fName2", 10, 20);
    b.signForm(f2);

    Form f3("fName3", 15, 20);
    b.signForm(f3);
}
