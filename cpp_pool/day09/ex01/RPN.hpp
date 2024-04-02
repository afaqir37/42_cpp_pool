#ifndef _RPN_HPP_
#define _RPN_HPP_

#include <iostream>
#include <sstream>
#include <stack>
#include <string.h>
#include <cstdlib>

class CalculatorRPN {
private:
     std::string _expression;

public:
    CalculatorRPN(std::string expression);
    CalculatorRPN(const CalculatorRPN& other);
    CalculatorRPN& operator=(const CalculatorRPN& other);
    ~CalculatorRPN();

    void parseAndCalculate();
    bool isValid(std::string& token);
};

#endif