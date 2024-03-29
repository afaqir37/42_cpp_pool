#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
private:
    unsigned int N;
    std::vector<int> arr;

public:
    Span(unsigned int N);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void printArr();
    
};

#endif