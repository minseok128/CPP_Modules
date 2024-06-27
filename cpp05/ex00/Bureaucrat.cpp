#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	_setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
	: _name(obj._name), _grade(obj._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this != &obj) {
		this->~Bureaucrat();
		new (this) Bureaucrat(obj);
	}
	return (*this);
}

std::string Bureaucrat::getName() const { return (_name); }

int Bureaucrat::getGrade() const { return (_grade); }

void Bureaucrat::incrementGrade() { _setGrade(_grade - 1); }

void Bureaucrat::decrementGrade() { _setGrade(_grade + 1); }

void Bureaucrat::_setGrade(int grade) {
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	_grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("grade is greater than the maximum value");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("grade is less than the minimum value");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}
