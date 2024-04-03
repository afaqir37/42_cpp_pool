#ifndef _PMERGEME_HPP_
#define _PMERGEME_HPP_

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>

class CustomSort {
public:
    CustomSort(std::string expression);
    CustomSort(const CustomSort& other);
    CustomSort& operator=(const CustomSort& other);
    ~CustomSort();

    void parse();
    void sortVec();
    void makePairs(std::vector<std::pair<int, int> >& pairs);
    void mergeSort(std::vector<std::pair<int, int> >& pairs, int start, int end);
    void merge(std::vector<std::pair<int, int> >& pairs, int start, int mid, int end);
    void print();

private:
    std::string _expression;
    std::vector<int> vec;
    std::list<int> list;
};

#endif