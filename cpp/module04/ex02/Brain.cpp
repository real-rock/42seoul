/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:17:03 by jiheo             #+#    #+#             */
/*   Updated: 2022/09/23 07:42:56 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {}

Brain::Brain(const Brain &b) {
    _copy(b);
}

Brain::~Brain() {}

Brain &Brain::operator=(const Brain &b) {
    _copy(b);
    return *this;
}

void Brain::_copy(const Brain &b) {
    for (int i = 0; i < MAX_SIZE; i++) {
        _ideas[i] = b._ideas[i];
    }
}

const std::string *Brain::getIdeas() const {
    return _ideas;
}

void Brain::setIdea(int idx, const std::string s) {
    if (idx < MAX_SIZE)
        _ideas[idx] = s;
}
