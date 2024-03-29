#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template<typename T>
typename T::iterator easyfind(T &container, int i) {
    typename T::iterator it = std::find(container.begin(), container.end(), i);
    if (it == container.end())
        throw (std::exception());
    return it;
}

#endif