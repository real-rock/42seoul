/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:37:40 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/13 14:48:24 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string s = "HI THIS IS BRAIN";

    std::string *strPTR = &s;
    std::string &strREF = s;

    std::cout << "strPTR: " << (void *)strPTR << " strREF: " << (void *)&strREF << '\n';
    std::cout << "strPTR: " << *strPTR << " strREF: " << strREF << '\n';
}
