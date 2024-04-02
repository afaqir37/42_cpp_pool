#include "PmergeMe.hpp"

CustomSort::CustomSort(std::string expression) : _expression(expression) {
    parse();
}

CustomSort::CustomSort(const CustomSort& other) {
    *this = other;
}

CustomSort& CustomSort::operator=(const CustomSort& other) {
    _expression = other._expression;
    return *this;
}

CustomSort::~CustomSort() {}

void CustomSort::parse() {
    std::set<int> dup;

    std::istringstream ss(_expression);
    std::string token;

    while (ss >> token) {
        char *endptr;
        long int num = strtol(token.c_str(), &endptr, 10);
        if (*endptr != '\0' || num < 0)
            throw std::runtime_error("Error: Bad Expression");
        dup.insert(num);
        vec.push_back(num);
        
    }
    if (dup.size() != vec.size())
        throw std::runtime_error("Error: Duplicate Element");
}

void CustomSort::print() {
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " " ;
    }
    std::cout << std::endl;
}



