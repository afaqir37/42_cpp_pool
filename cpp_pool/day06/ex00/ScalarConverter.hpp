#ifndef _SCALARCONVERTER_HPP_
#define _SCALARCONVERTER_HPP_

#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <cfloat>

class ScalarConverter
{
    private:
        std::string _value;
        ScalarConverter();
    public:
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter &operator=(ScalarConverter const &other);
        ~ScalarConverter();

        static void convert(const std::string& str);
};



#endif