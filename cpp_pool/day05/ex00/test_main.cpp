#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John Doe", 150);
        std::cout << "Bureaucrat created successfully!" << std::endl;
        
        // Attempt to increment the grade beyond the maximum allowed
        bureaucrat.incrementGrade();
        std::cout << "Grade incremented successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John Doe", 150);
        bureaucrat.incrementGrade(); // This should throw an exception
        std::cout << "Grade: " << bureaucrat.getGrade() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}