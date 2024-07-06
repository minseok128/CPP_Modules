/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:04:20 by michang           #+#    #+#             */
/*   Updated: 2024/07/06 19:38:56 by michang          ###   ########.fr       */
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

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	static int isInitialized = 0;

	AForm::checkExecutePermission(executor);
	std::cout << "*drilling noises*\n";
	if (!isInitialized) {
		std::srand(static_cast<unsigned int>(std::time(0)));
		isInitialized = 1;
	}

	if (std::rand() % 2)
		std::cout << getName() << " has been robotomized successfully\n";
	else
		std::cout << getName() << " robotomization failed\n";
}