#include "Bureaucrat.hpp"

int main(void) {

    try {

        Bureaucrat bureaucrat("John Doe", 151);
        std::cout << bureaucrat;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {

        Bureaucrat bureaucrat("John Doe", 0);
        std::cout << bureaucrat;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;

    }


    try {

        Bureaucrat bureaucrat("John Doe", 150);
        std::cout << bureaucrat;
        bureaucrat.decrementGrade();
        std::cout << "Grade decremented successfully!" << std::endl;

    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {

        Bureaucrat bureaucrat("John Doe", 1);
        std::cout << bureaucrat;
        bureaucrat.incrementGrade();
        std::cout << "Grade incremented successfully!" << std::endl;

    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
}


}