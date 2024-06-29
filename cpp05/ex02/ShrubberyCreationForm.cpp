/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:03:57 by michang           #+#    #+#             */
/*   Updated: 2024/06/29 20:57:14 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("default target", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
	: AForm(obj) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	if (this != &obj) {
		this->~ShrubberyCreationForm();
		new (this) ShrubberyCreationForm(obj);
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {}