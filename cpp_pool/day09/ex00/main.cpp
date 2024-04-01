#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./bitcoin filename" << std::endl;
        return 1;
    }
    BitcoinExchange exchange(argv[1], "data.csv");
  // exchange.printDataBase();
   // exchange.print();
    std::cout << "-------------------\n";
    return 0;

}