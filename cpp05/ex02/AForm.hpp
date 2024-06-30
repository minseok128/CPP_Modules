/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:09:06 by michang           #+#    #+#             */
/*   Updated: 2024/06/30 15:05:19 by michang          ###   ########.fr       */
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
	virtual ~AForm();
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& obj);
	virtual void execute(Bureaucrat const& executor) const = 0;

  protected:
	class GradeTooHighException : public std::exception {
	  private:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	  private:
		virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception {
	  private:
		virtual const char* what() const throw();
	};
	class FileNotOpenException : public std::exception {
	  private:
		virtual const char* what() const throw();
	};

	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& obj);
	virtual AForm& operator=(const AForm& obj);
	void checkExecutePermission(const Bureaucrat& executor) const;

  private:
	std::string _name;
	bool _signed;
	int _gradeToSign;
	int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
