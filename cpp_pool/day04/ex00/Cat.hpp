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