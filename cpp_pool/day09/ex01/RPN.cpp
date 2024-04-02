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

bool CalculatorRPN::isValid(std::string& token) {
    char *endptr;
    long int number = strtol(token.c_str(), &endptr, 10);
    if (*endptr != '\0')
        return false;
    else {
        if (token[0] == '+' || number >= 10)
            return false;
    }
    return true;
}

void CalculatorRPN::parseAndCalculate() {
    std::istringstream ss(_expression);
    std::string token;
    std::stack<int> myStack;

    while (ss >> token) {
            if (isValid(token))
                myStack.push(atoi(token.c_str()));
            else if (token == "+" || token == "-" || token == "*" || token == "/"){
                if (myStack.size() < 2)
                    throw std::runtime_error("Not enough operands for the operator");
                
                int num1 = myStack.top();
                myStack.pop();
                int num2 = myStack.top();
                myStack.pop();
                if (token == "+")
                    myStack.push(num2 + num1);
                else if (token == "-")
                    myStack.push(num2 - num1);
                else if (token == "*")
                    myStack.push(num2 * num1);
                else if (token == "/") {
                    if (num1 == 0)
                        throw std::runtime_error("Error: Cannot divide by 0");
                    myStack.push(num2 / num1);
                }
                
            }
            else
                throw std::runtime_error("Error: Bad Expression");
        }

        if (myStack.size() == 1)
            std::cout << myStack.top() << std::endl;
        else
            throw std::runtime_error("Error: Bad Expression");
    }
