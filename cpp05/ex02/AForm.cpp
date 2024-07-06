/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:08:23 by michang           #+#    #+#             */
/*   Updated: 2024/07/06 20:04:27 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name("default"), _signed(0), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, std::string target, int gradeToSign,
			 int gradeToExecute)
	: _name(name), _target(target), _signed(0) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	_gradeToSign = gradeToSign;
	_gradeToExecute = gradeToExecute;
}

AForm::AForm(const AForm& obj)
	: _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign),
	  _gradeToExecute(obj._gradeToExecute) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& obj) {
	if (this != &obj)
		return (*this);
	return (*this);
}

std::string AForm::getName() const { return (_name); }

std::string AForm::getTarget() const { return (_target); }

int AForm::getSigned() const { return (_signed); }

int AForm::getGradeToSign() const { return (_gradeToSign); }

int AForm::getGradeToExecute() const { return (_gradeToExecute); }

void AForm::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = 1;
}

void AForm::checkExecutePermission(const Bureaucrat& executor) const {
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed");
}

const char* AForm::FileNotOpenException::what() const throw() {
	return ("File is not open");
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << obj.getName();
	if (obj.getSigned())
		os << " is signed and the Grade required to sign is ";
	else
		os << " is not signed and the Grade required to sign is ";
	os << obj.getGradeToSign() << " and Grade required to execute is "
	   << obj.getGradeToExecute();
	return (os);
}
