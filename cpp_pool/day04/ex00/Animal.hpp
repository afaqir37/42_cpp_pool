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
         ~Animal();

          std::string getType(void) const;
        virtual void makeSound(void) ;
};


#endif