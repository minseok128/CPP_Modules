#include "Form.hpp"

Form::Form()
	: _name("default"),
	  _signed(false),
	  _gradeToSign(150),
	  _gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name),
	  _signed(false),
	  _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute) {}

Form::Form(const Form& obj)
	: _name(obj._name),
	  _signed(obj._signed),
	  _gradeToSign(obj._gradeToSign),
	  _gradeToExecute(obj._gradeToExecute) {}

Form::~Form() {}

Form& Form::operator=(const Form& obj) {
	if (this != &obj) {
		this->~Form();
		new (this) Form(obj);
	}
	return (*this);
}

std::string Form::getName() const { return (_name); }

void Form::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() > _gradeToSign) throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form grade is too high");
}