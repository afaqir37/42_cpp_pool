#include <iostream>

class BaseException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Base exception";
        }
};

class DerivedException : public BaseException {
    public:
        virtual const char *what() const throw() {
            return "Child exception";
        }
};

void functionThatThrows() {
    throw DerivedException();
}

int main() {
    try {
        functionThatThrows();
    }
    catch (BaseException &e) {
        std::cout << e.what() << std::endl;
    }
}