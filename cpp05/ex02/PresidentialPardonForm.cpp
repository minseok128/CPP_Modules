/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:04:45 by michang           #+#    #+#             */
/*   Updated: 2024/06/29 20:47:29 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("default target", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm(target, 25, 5) {}

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
