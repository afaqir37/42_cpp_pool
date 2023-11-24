/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:18:35 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:18:36 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_
#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal(std::string name = "Animal");
        Animal(Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();

        std::string getType(void) const;
        virtual void makeSound(void) const;
};


#endif