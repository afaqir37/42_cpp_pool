#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    std::string const name;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExecute;

public:
    Form();
    Form(std::string const & name, int gradeToSign, int gradeToExecute);
    Form(Form& other);
    Form& operator=(const Form& other);
    virtual ~Form();

    std::string const & getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif