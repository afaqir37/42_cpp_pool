#include "RPN.hpp"

CalculatorRPN::CalculatorRPN(std::string expression) : _expression(expression) {}

CalculatorRPN::CalculatorRPN(const CalculatorRPN& other) {
    *this = other;
}

CalculatorRPN& CalculatorRPN::operator=(const CalculatorRPN& other) {
    _expression = other._expression;
    return *this;
}

CalculatorRPN::~CalculatorRPN() {}

void CalculatorRPN::parseAndCalculate() {
    std::istringstream ss(_expression);
    std::string token;
    std::stack<int> myStack;

    while (ss >> token) {
        if (isdigit(token[0])) {
            if (strlen(token.c_str()) != 1)
                throw std::runtime_error("Number is greater than 10!");
            myStack.push(atoi(token.c_str()));
        }
    }
}