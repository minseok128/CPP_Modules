/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:17:30 by michang           #+#    #+#             */
/*   Updated: 2024/07/06 21:33:09 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Intern {
  public:
	Intern();
	Intern(const Intern& obj);
	~Intern();
	Intern& operator=(const Intern& obj);
	AForm* makeForm(std::string formName, std::string target) const;

  private:
	AForm* makeShrubberyCreationForm(std::string target) const;
	AForm* makeRobotomyRequestForm(std::string target) const;
	AForm* makePresidentialPardonForm(std::string target) const;
	class FormNotFoundException : public std::exception {
	  private:
		virtual const char* what() const throw();
	};
};

#endif