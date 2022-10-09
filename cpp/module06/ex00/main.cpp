/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:02:55 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/05 16:24:14 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Invalid arguments" << std::endl;
        exit(EXIT_FAILURE);
    }
    Converter c(argv[1]);
    try {
        c.parse();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    c.print_all();
}
