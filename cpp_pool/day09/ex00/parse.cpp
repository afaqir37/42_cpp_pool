#include <iostream>

#include <fstream>
#include <map>
#include <iostream>
#include <sstream>

int main() {
    std::string str = "202";

    char *endptr;
    long int test = strtol(str.c_str(), &endptr, 10);
    if (*endptr == '\0') {
        std::cout << "num: " << test << '\n';
    } else {
        std::cout << "Error\n";
    }
}