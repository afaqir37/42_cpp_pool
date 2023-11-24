/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:17:23 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:17:24 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
#define _CAT_HPP_
#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();

        void makeSound(void) const;
};

#endif