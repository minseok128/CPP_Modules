/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:17:43 by michang           #+#    #+#             */
/*   Updated: 2024/07/07 19:30:48 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj) { (void)obj; }

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& obj) {
	if (this != &obj)
		return (*this);
	return (*this);
}

AForm* Intern::makeShrubberyCreationForm(std::string target) const {
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequestForm(std::string target) const {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(std::string target) const {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string target) const {
	static AForm* (Intern::*functions[3])(std::string) const = {
		&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm};
	static std::string arr[3] = {"shrubbery creation", "robotomy request",
								 "presidential pardon"};
	AForm* form = 0;

	for (int i = 0; i < 3; i++)
		if (formName == arr[i])
			form = (this->*functions[i])(target);

	if (!form)
		throw Intern::FormNotFoundException();
	std::cout << "Intern creates " << formName << std::endl;
	return (form);
}

const char* Intern::FormNotFoundException::what() const throw() {
	return ("Form name not found");
}