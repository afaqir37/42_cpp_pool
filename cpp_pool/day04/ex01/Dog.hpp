/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:20:42 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:26:20 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
#define _DOG_HPP_
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* brain;
    public:
        Dog();
        Dog(Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        void makeSound(void) const;
        void getter(void);
        void setter(int index, std::string str);
};

#endif