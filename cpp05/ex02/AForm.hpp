/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:09:06 by michang           #+#    #+#             */
/*   Updated: 2024/06/29 20:09:07 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
  public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& obj);
	~AForm();
	AForm& operator=(const AForm& obj);
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& obj);

  private:
	std::string _name;
	bool _signed;
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

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
