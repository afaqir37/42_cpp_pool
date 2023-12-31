/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:17:26 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:17:27 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructor called\n";
    type = "Dog";
}

Dog::Dog(Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called\n";
    type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called\n";
    if (this != &other)
    {
        type = other.type;
    }
    return *this;

}

Dog::~Dog() {
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound(void) const{
    std::cout << "Dog sound: wouaff\n";
}