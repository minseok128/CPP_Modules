/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:23:49 by michang           #+#    #+#             */
/*   Updated: 2024/06/29 20:14:09 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		std::cout << "Bureaucrat 'A' grade '1'\n\n";
		Bureaucrat A("A", 1);
		std::cout << A << "\n\n";

		ShrubberyCreationForm shrubberyForm("seonjo1");
		RobotomyRequestForm roboForm1("seonjo1");
		RobotomyRequestForm roboForm2("seonjo1");
		RobotomyRequestForm roboForm3("seonjo1");
		PresidentialPardonForm PardonForm("seonjo1");

		A.signForm(shrubberyForm);
		A.signForm(roboForm1);
		A.signForm(roboForm2);
		A.signForm(roboForm3);
		A.signForm(PardonForm);

		A.executeForm(shrubberyForm);
		A.executeForm(roboForm1);
		A.executeForm(roboForm2);
		A.executeForm(roboForm3);
		A.executeForm(PardonForm);
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << "\n\nBureaucrat 'B' grade '50'\n\n";
		Bureaucrat B("B", 50);
		std::cout << B << "\n\n";

		ShrubberyCreationForm shrubberyForm("seonjo2");
		RobotomyRequestForm roboForm1("seonjo2");
		RobotomyRequestForm roboForm2("seonjo2");
		RobotomyRequestForm roboForm3("seonjo2");
		PresidentialPardonForm PardonForm("seonjo2");

		B.signForm(shrubberyForm);
		B.signForm(roboForm1);
		B.signForm(roboForm2);
		B.signForm(roboForm3);
		B.signForm(PardonForm);

		B.executeForm(shrubberyForm);
		B.executeForm(roboForm1);
		B.executeForm(roboForm2);
		B.executeForm(roboForm3);
		B.executeForm(PardonForm);
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << "\n\nBureaucrat 'C' grade '150'\n\n";
		Bureaucrat C("C", 150);
		std::cout << C << "\n\n";

		ShrubberyCreationForm shrubberyForm("seonjo3");
		RobotomyRequestForm roboForm1("seonjo3");
		RobotomyRequestForm roboForm2("seonjo3");
		RobotomyRequestForm roboForm3("seonjo3");
		PresidentialPardonForm PardonForm("seonjo3");

		C.signForm(shrubberyForm);
		C.signForm(roboForm1);
		C.signForm(roboForm2);
		C.signForm(roboForm3);
		C.signForm(PardonForm);

		C.executeForm(shrubberyForm);
		C.executeForm(roboForm1);
		C.executeForm(roboForm2);
		C.executeForm(roboForm3);
		C.executeForm(PardonForm);
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return (0);
}