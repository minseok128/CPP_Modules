/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:04:20 by michang           #+#    #+#             */
/*   Updated: 2024/06/29 20:44:53 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default target", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: AForm(obj) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	if (this != &obj) {
		this->~RobotomyRequestForm();
		new (this) RobotomyRequestForm(obj);
	}
	return (*this);
}
