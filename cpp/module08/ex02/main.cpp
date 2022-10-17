/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:44 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/17 12:17:01 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << std::endl;

    std::stack<int> s(mstack);

    mstack.pop();
    for (MutantStack<int>::iterator i = mstack.begin(); i != mstack.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;
    
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
    return 0;
}

// int main() {
//     std::list<int> mstack;
//     mstack.push_back(5);
//     mstack.push_back(17);
//     std::cout << mstack.back() << std::endl;
//     mstack.pop_back();
//     std::cout << mstack.size() << std::endl;
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     mstack.push_back(0);
//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     std::cout << std::endl;

//     std::list<int> s(mstack);

//     mstack.pop_back();
//     for (std::list<int>::iterator i = mstack.begin(); i != mstack.end(); i++)
//         std::cout << *i << " ";
//     std::cout << std::endl;
    
//     while (!s.empty()) {
//         std::cout << s.back() << " ";
//         s.pop_back();
//     }
//     std::cout << std::endl;
//     return 0;
// }
