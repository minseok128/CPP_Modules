#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
  public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& obj);
	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm& obj) const;
	void executeForm(const AForm& form);

  private:
	void _setGrade(int amount);
	const std::string _name;
	int _grade;

	class GradeTooHighException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
