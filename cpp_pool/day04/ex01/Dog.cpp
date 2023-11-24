/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:20:34 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:26:47 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructor called\n";
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called\n";
    type = other.type;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called\n";
    if (this != &other)
    {
        type = other.type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;

}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound(void) const{
    std::cout << "Dog sound: wouaff\n";
}

void Dog::getter(void) {
    brain->getIdeas();
}

void Dog::setter(int index, std::string str) {
    brain->setIdeas(index, str);
}