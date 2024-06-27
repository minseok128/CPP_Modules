#ifndef FORM_HPP
#define FORM_HPP
#include <exception>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
public:
    Form();
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &obj);
    ~Form();
    Form &operator=(const Form &obj);
    std::string getName() const;
    void beSigned(const Bureaucrat &obj);

private:
    std::string _name;
    bool _signed;
    int _gradeToSign;
    int _gradeToExecute;

    class GradeTooHighException : public std::exception
    {
    private:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    private:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
