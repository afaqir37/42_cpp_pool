#ifndef _CAT_HPP_
#define _CAT_HPP_
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* brain;
    public:
        Cat();
        Cat(Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();

        void makeSound(void) const;
        void getter(void);
        void setter(int index, std::string str);
};

#endif