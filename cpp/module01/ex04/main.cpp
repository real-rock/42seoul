/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:00:41 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/13 16:57:47 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void replace(std::string &src, const std::string &s1, const std::string &s2) {
    std::string res;
    std::size_t left_pos = 0;
    std::size_t right_pos = 0;

    while ((right_pos = src.find(s1, left_pos)) != std::string::npos) {
        res += src.substr(left_pos, right_pos - left_pos);
        res += s2;
        left_pos = right_pos + s1.length();
    }
    res += src.substr(left_pos, std::string::npos);
    src = res;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cout << "Invalid argument\n";
        return 1;
    }
    std::string org_file(argv[1]);
    std::string rep_file = org_file + ".replace";

    std::ifstream file(org_file.data());
    if (!file.is_open()) {
        std::cout << "Failed to read file\n";
        return 1;
    }
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    replace(str, argv[2], argv[3]);

    std::ofstream writeFile(rep_file.data());
    if (writeFile.is_open()) {
        writeFile << str;
        writeFile.close();
    }
}