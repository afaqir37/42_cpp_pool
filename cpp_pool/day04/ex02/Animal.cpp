/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:31:23 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:31:24 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(std::string name) {
    std::cout << "Animal constructor called\n";
    type = name;
}

Animal::Animal(Animal& other) {
    std::cout << "Animal copy constructor called\n";
    type = other.type;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment operator\n";
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

 Animal::~Animal() {
    std::cout << "Animal destructor called\n";
}

 void Animal:: makeSound(void) const{
    std::cout << "each animal has a specific sound\n";
}

std::string Animal::getType(void) const {
    return type;
}