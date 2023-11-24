/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:21:06 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:21:11 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat constructor called\n";
    type = "WrongCat";
}

WrongCat::WrongCat(WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called\n";
    type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator called\n";
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound(void) const{
    std::cout << "Wrong Meow!\n";
}