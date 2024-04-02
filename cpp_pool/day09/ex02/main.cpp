#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "Usage: [program] [list of numbers to sort]\n";
        return 1;
    }
    else {
        std::string list = argv[1];
        if (argc != 2) {
            for (int i = 2; argv[i]; i++) {
                list += " ";
                list += argv[i];
            }
        }
        try {
            CustomSort obj(list);
            obj.print();
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}