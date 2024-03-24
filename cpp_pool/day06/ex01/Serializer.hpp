#ifndef _SERIALIZER_HPP_
#define _SERIALIZER_HPP_

#include <iostream>
#include <stdint.h>

struct Data {
    std::string s1;
    int n;
    std::string s2;
};

class Serializer {
    private:
        Serializer();
    public:
        Serializer(Serializer const &other);
        Serializer &operator=(Serializer const &other);
        ~Serializer();

        static uintptr_t serialize(Data* ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif