/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:17:41 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:17:42 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string name) {
    std::cout << "WrongAnimal constructor called\n";
    type = name;
}

WrongAnimal::WrongAnimal(WrongAnimal& other) {
    std::cout << "WrongAnimal copy constructor called\n";
    type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy assignment operator\n";
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

 WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called\n";
}

 void WrongAnimal:: makeSound(void) const{
    std::cout << "each wrongAnimal has a specific sound\n";
}

std::string WrongAnimal::getType(void) const {
    return type;
}