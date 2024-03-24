#include <iostream>
#include <cmath>
#include <climits>

int main(int argc, char **argv) {
    double val;
    
    val = atof(argv[1]);

    if (val < CHAR_MIN || val > CHAR_MAX)
        std::cout << "tnakt\n";
    else if (isprint(static_cast<char>(val)))
        std::cout << static_cast<char>(val) << std::endl;
    else
        std::cout << "char non printable\n";
}