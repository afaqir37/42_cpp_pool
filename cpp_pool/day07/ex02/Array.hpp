#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <iostream>
#include <cstdlib>

template<typename T>
class Array {
private:
    T* arr;
    unsigned int length;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;

    class OutOfRangeException : public std::exception {
        public:
            virtual const char * what() const throw();
    };
};

#include "Array.tpp"
#endif