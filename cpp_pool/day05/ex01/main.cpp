#include "Bureaucrat.hpp"

int main(void) {

    try {
        Form contract("Contract", 20, 20);
        std::cout << contract;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Form contract("Contract", 0, 20);
        std::cout << contract;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("John Doe", 20);
        std::cout << bureaucrat;
        Form contract("Contract", 20, 20);
        bureaucrat.signForm(contract);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("John Doe", 20);
        std::cout << bureaucrat;
        Form contract("Contract", 4, 20);
        bureaucrat.signForm(contract);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("John Doe", 1);
        std::cout << bureaucrat;
        Form contract("Contract", 4, 20);
        try {
            contract.beSigned(bureaucrat);
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        
        }
        bureaucrat.signForm(contract);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

}