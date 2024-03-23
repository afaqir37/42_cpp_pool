#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

    Intern intern;
    AForm* form;

    form = intern.makeForm("shrubbery creation", "home");
    if (form) {
        Bureaucrat bureaucrat("John Doe", 20);
        std::cout << bureaucrat;
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
    }

}