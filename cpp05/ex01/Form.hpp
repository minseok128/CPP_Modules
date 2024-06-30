/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:36:37 by michang           #+#    #+#             */
/*   Updated: 2024/06/30 16:46:37 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form& obj);
	~Form();
	Form& operator=(const Form& obj);
	std::string getName() const;
	int getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& obj);

  private:
	std::string _name;
	int _signed;
	int _gradeToSign;
	int _gradeToExecute;

	class GradeTooHighException : public std::exception {
	  private:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	  private:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif