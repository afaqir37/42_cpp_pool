#ifndef _DOG_HPP_
#define _DOG_HPP_
#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        void makeSound(void) const;
};

#endif