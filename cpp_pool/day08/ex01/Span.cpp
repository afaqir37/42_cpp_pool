#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

Span::Span(Span const &other) {
    *this = other;
}

Span &Span::operator=(Span const &other) {
    N = other.N;
    arr = other.arr;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (arr.size() >= N)
        throw std::exception();

    arr.push_back(n);
}

int Span::shortestSpan() {
    if (arr.size() < 2)
        throw std::exception();

    std::vector<int> sorted = arr;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];

    for (unsigned int i = 2; i < arr.size(); i++) {
        min = (sorted[i] - sorted[i - 1] < min) ? sorted[i] - sorted[i - 1] : min;
    }

    return min;
}

int Span::longestSpan() {
    if (arr.size() < 2)
        throw std::exception();

    std::vector<int> sorted = arr;
    std::sort(sorted.begin(), sorted.end());
    return (sorted.back() - sorted.front());
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (arr.size() >= N)
        throw std::exception();

    while (begin != end) {
        addNumber(*begin);
        begin++;
    }

}

void Span::printArr() {
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}