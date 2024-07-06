/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:23:49 by michang           #+#    #+#             */
/*   Updated: 2024/07/06 21:37:14 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// #include <cstdlib>
// void leaks_check()
// {
// 	system("leaks _ex03");
// }

int main() {
	Intern intern;
	AForm* form;

	try {
		std::cout << "Bureaucrat 'A' grade '1'\n\n";
		Bureaucrat A("A", 1);
		std::cout << A << "\n\n";

		form = intern.makeForm("shrubbery creation", "michang1");
		if (form) {
			A.signForm(*form);
			A.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("robotomy request", "michang1");
		if (form) {
			A.signForm(*form);
			A.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("presidential pardon", "michang1");
		if (form) {
			A.signForm(*form);
			A.executeForm(*form);
			delete form;
		}
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << "\n\nBureaucrat 'B' grade '50'\n\n";
		Bureaucrat B("B", 50);
		std::cout << B << "\n\n";

		form = intern.makeForm("shrubbery creation", "michang2");
		if (form) {
			B.signForm(*form);
			B.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("robotomy request", "michang2");
		if (form) {
			B.signForm(*form);
			B.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("presidential pardon", "michang2");
		if (form) {
			B.signForm(*form);
			B.executeForm(*form);
			delete form;
		}
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << "\n\nBureaucrat 'C' grade '150'\n\n";
		Bureaucrat C("C", 150);
		std::cout << C << "\n\n";

		form = intern.makeForm("shrubbery creation", "michang3");
		if (form) {
			C.signForm(*form);
			C.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("robotomy request", "michang3");
		if (form) {
			C.signForm(*form);
			C.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("presidential pardon", "michang3");
		if (form) {
			C.signForm(*form);
			C.executeForm(*form);
			delete form;
		}
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << "\n\nBureaucrat 'D' grade '33'\n\n";
		Bureaucrat D("D", 33);
		std::cout << D << "\n\n";

		form = intern.makeForm("Shrubbery creation", "michang4");
		if (form) {
			D.signForm(*form);
			D.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("robotomyrequest", "michang4");
		if (form) {
			D.signForm(*form);
			D.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("presidential pardon ", "michang4");
		if (form) {
			D.signForm(*form);
			D.executeForm(*form);
			delete form;
		}
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	// atexit(leaks_check);

	return (0);
}