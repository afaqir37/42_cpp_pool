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
};

#endif