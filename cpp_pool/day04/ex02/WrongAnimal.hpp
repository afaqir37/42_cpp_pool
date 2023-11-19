#ifndef _WRONG_ANIMAL_HPP_
#define _WRONG_ANIMAL_HPP_
#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal(std::string name = "WrongAnimal");
        WrongAnimal(WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();

        std::string getType(void) const;
        void makeSound(void) const;
};


#endif