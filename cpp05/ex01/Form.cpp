/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:36:50 by michang           #+#    #+#             */
/*   Updated: 2024/06/30 16:36:58 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name("default"), _signed(false), _gradeToSign(150),
	  _gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	_gradeToSign = gradeToSign;
	_gradeToExecute = gradeToExecute;
}

Form::Form(const Form& obj)
	: _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign),
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

bool Form::getSigned() const { return (_signed); }

int Form::getGradeToSign() const { return (_gradeToSign); }

int Form::getGradeToExecute() const { return (_gradeToExecute); }

void Form::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << obj.getName();
	if (obj.getSigned())
		os << " is signed and the Grade required to sign is ";
	else
		os << " is not signed and the Grade required to sign is ";
	os << obj.getGradeToSign() << " and Grade required to execute is "
	   << obj.getGradeToExecute();
	return (os);
}