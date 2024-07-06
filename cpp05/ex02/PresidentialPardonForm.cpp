/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:04:45 by michang           #+#    #+#             */
/*   Updated: 2024/07/06 19:50:58 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", "default target", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& obj)
	: AForm(obj) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	if (this != &obj) {
		this->~PresidentialPardonForm();
		new (this) PresidentialPardonForm(obj);
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!getSigned())
		throw AForm::FormNotSignedException();
	else if (getGradeToExecute() > executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"
			  << std::endl;
}