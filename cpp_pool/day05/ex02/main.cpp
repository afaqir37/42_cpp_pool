#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

    try {
        Bureaucrat bureaucrat("John Doe", 20);
        std::cout << bureaucrat;
        ShrubberyCreationForm shrubbery("Shrubbery");
        bureaucrat.signForm(shrubbery);
        bureaucrat.executeForm(shrubbery);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("John Doe", 20);
        std::cout << bureaucrat;
        RobotomyRequestForm robotomy("Robotomy");
        bureaucrat.signForm(robotomy);
        bureaucrat.executeForm(robotomy);
        bureaucrat.executeForm(robotomy);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("John Doe", 3);
        std::cout << bureaucrat;
        PresidentialPardonForm presidential("Presidential");
        bureaucrat.signForm(presidential);
        bureaucrat.executeForm(presidential);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // try {
    //     Bureaucrat bureaucrat("John Doe", 150);
    //     std::cout << bureaucrat;
    //     ShrubberyCreationForm shrubbery("Shrubbery");
    //     bureaucrat.signForm(shrubbery);
    //     bureaucrat.executeForm(shrubbery);
    //     shrubbery.execute(bureaucrat);
    // } catch (std::exception &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat bureaucrat("John Doe", 139);
    //     std::cout << bureaucrat;
    //     ShrubberyCreationForm shrubbery("Shrubbery");
    //     bureaucrat.signForm(shrubbery);
    //     bureaucrat.executeForm(shrubbery);
    //     shrubbery.execute(bureaucrat);
    // } catch (std::exception &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat bureaucrat("John Doe", 122);
    //     std::cout << bureaucrat;
    //     RobotomyRequestForm robotomy("Robotomy");
    //     bureaucrat.signForm(robotomy);
    //     bureaucrat.executeForm(robotomy);
    //     robotomy.execute(bureaucrat);
    // } catch (std::exception &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat bureaucrat("John Doe", 70);
    //     std::cout << bureaucrat;
    //     RobotomyRequestForm robotomy("Robotomy");
    //     bureaucrat.signForm(robotomy);
    //     bureaucrat.executeForm(robotomy);
    //     robotomy.execute(bureaucrat);
    // } catch (std::exception &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat bureaucrat("John Doe", 122);
    //     std::cout << bureaucrat;
    //     PresidentialPardonForm presidential("Presidential");
    //     bureaucrat.signForm(presidential);
    //     bureaucrat.executeForm(presidential);
    //     presidential.execute(bureaucrat);
    // } catch (std::exception &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat bureaucrat("John Doe", 20);
    //     std::cout << bureaucrat;
    //     PresidentialPardonForm presidential("Presidential");
    //     bureaucrat.signForm(presidential);
    //     bureaucrat.executeForm(presidential);
    //     presidential.execute(bureaucrat);
    // } catch (std::exception &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

}