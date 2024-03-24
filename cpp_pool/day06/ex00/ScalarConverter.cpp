#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &) {
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& str) {
    double val = atof(str.c_str());

    if (val < CHAR_MIN || val > CHAR_MAX || isnan(val))
        std::cout << "char: impossible\n";
    else if (isprint(static_cast<char>(val)))
        std::cout << "char: " << static_cast<char>(val) << std::endl;
    else
        std::cout << "char: Non displayable\n";

    if (val < INT_MIN || val > INT_MAX || isnan(val))
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    if (isnan(val))
        std::cout << "float: nanf\n";
    else if (val == INFINITY || val == -INFINITY)
        std::cout << "float: " << (val < 0 ? "-" : "") << "inff\n";
    else
        std::cout << "float: " << static_cast<float>(val) << ".0f\n";

    if (isnan(val))
        std::cout << "double: nan\n";
    else if (val == INFINITY || val == -INFINITY)
        std::cout << "double: " << (val < 0 ? "-" : "") << "inf\n";
    else
        std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;

    return;
}