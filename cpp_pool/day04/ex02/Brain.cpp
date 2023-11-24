/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:31:32 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:31:33 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called\n";
}

Brain::Brain(Brain& other) {
    std::cout << "Brain copy constructor called\n";
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "brain copy assignment operator\n";
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called\n";
}

void Brain::getIdeas(void) {
    for (int i = 0; i < 100; i++)
        std::cout << ideas[i] << '\n';
}

void Brain::setIdeas(int index, std::string str) {
    if (index < 0 || index >= 100)
        std::cout << "Please enter a valid index\n";
    else
        ideas[index] = str;
}