/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:12:31 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/23 07:42:54 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

#define MAX_SIZE 100

class Brain {
protected:
    std::string _ideas[MAX_SIZE];

    void _copy(const Brain &b);

public:
    Brain();
    Brain(const Brain &b);
    ~Brain();
    Brain &operator=(const Brain &b);

    const std::string *getIdeas() const;
    void setIdea(int idx, const std::string s);
};

#endif