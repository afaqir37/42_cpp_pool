#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & src) : std::stack<T>(src) {}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const & src) {
    if (this != &src) {
        std::stack<T>::operator=(src);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}


