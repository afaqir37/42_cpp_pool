#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
    std::string const name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(std::string const & name, int grade);
    Bureaucrat(Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    virtual ~Bureaucrat();

    std::string const & getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    void signForm(Form &form);

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif