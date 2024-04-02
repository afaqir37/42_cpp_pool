#ifndef _PMERGEME_HPP_
#define _PMERGEME_HPP_

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <sstream>
#include <cstdlib>

class CustomSort {
public:
    CustomSort(std::string expression);
    CustomSort(const CustomSort& other);
    CustomSort& operator=(const CustomSort& other);
    ~CustomSort();

    void parse();
    void print();

private:
    std::string _expression;
    std::vector<int> vec;
    std::list<int> list;
};

#endif