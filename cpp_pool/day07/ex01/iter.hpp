#ifndef _ITER_HPP_
#define _ITER_HPP_

#include <iostream>

template<typename T, typename Func>
void iter(T* arr, size_t length, Func func) {
    for (size_t i = 0; i < length; i++) {
        func(arr[i]);
    }
}

template<typename T>
void printElem(const T& x) {
    std::cout << x << std::endl;
}

#endif