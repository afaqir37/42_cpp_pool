/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:17:29 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/25 02:47:08 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
#define _DOG_HPP_
#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(Dog& other);
        Dog& operator=(const Dog& other);
        virtual ~Dog();

        void makeSound(void) const;
};

#endif