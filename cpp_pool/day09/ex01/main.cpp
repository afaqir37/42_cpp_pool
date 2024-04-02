#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: [program] [expression]\n";
        return 1;
    }

    CalculatorRPN calculator(argv[1]);

    try {
        calculator.parseAndCalculate();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}