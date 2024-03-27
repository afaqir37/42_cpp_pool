#ifndef _ARRAY_TPP_
#define _ARRAY_TPP_

#include "Array.hpp"

template<typename T>
Array<T>::Array() : arr(NULL), length(0) { }

template<typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), length(n) { }


template<typename T>
Array<T>::Array(const Array<T>& other) {
    length = other.length;
    arr = new T[length];
    for (unsigned int i = 0; i < length; i++)
        arr[i] = other[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] arr;
        length = other.length;
        arr = new T[length];
        for (unsigned int i = 0; i < length; i++)
            arr[i] = other[i];
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] arr;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)  {
    if (index >= length)
        throw Array<T>::OutOfRangeException();
    return arr[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= length)
        throw Array::OutOfRangeException();
    return arr[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return length;
}

template<typename T>
const char * Array<T>::OutOfRangeException::what() const throw() {
    return "Array index out of bounds";
}

#endif