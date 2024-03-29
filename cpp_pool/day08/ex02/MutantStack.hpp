#ifndef _MUTANTSTACK_HPP_
#define _MUTANTSTACK_HPP_

#include <iostream>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    MutantStack(MutantStack const & src);
    MutantStack & operator=(MutantStack const & src);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() {
        return std::stack<T>::c.begin();
    }
    iterator end() {
        return std::stack<T>::c.end();
    
    }


};

#include "MutantStack.tpp"
#endif