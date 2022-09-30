/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:42:35 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/30 17:13:16 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat b("bur", 15);
    std::cout << b << std::endl;
    try {
        Bureaucrat c("cur", 15151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    b.setGrade(3);

    Form f("form", 25, 10);
    std::cout << f << std::endl;
    b.signForm(f);
}
