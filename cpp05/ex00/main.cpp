/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:23:49 by michang           #+#    #+#             */
/*   Updated: 2024/06/26 21:15:05 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "\n\nINCREMENT GRADE TEST\n\n";
		try
		{
			std::cout << "Create Bureaucrat 'A' grade '0'\n";
			Bureaucrat A("A", 0);
			std::cout << A << std::endl;
			A.incrementGrade();
			std::cout << A << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Create Bureaucrat 'B' grade '1'\n";
			Bureaucrat B("B", 1);
			std::cout << B << std::endl;
			B.incrementGrade();
			std::cout << B << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Create Bureaucrat 'C' grade '75'\n";
			Bureaucrat C("C", 75);
			std::cout << C << std::endl;
			C.incrementGrade();
			std::cout << C << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Create Bureaucrat 'D' grade '150'\n";
			Bureaucrat D("D", 150);
			std::cout << D << std::endl;
			D.incrementGrade();
			std::cout << D << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Create Bureaucrat 'E' grade '151'\n";
		try
		{
			Bureaucrat E("E", 151);
			std::cout << E << std::endl;
			E.incrementGrade();
			std::cout << E << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n\nDECREMENT GRADE TEST\n\n";
		try
		{
			std::cout << "Create Bureaucrat 'A' grade '0'\n";
			Bureaucrat A("A", 0);
			std::cout << A << std::endl;
			A.decrementGrade();
			std::cout << A << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Create Bureaucrat 'B' grade '1'\n";
			Bureaucrat B("B", 1);
			std::cout << B << std::endl;
			B.decrementGrade();
			std::cout << B << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Create Bureaucrat 'C' grade '75'\n";
			Bureaucrat C("C", 75);
			std::cout << C << std::endl;
			C.decrementGrade();
			std::cout << C << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Create Bureaucrat 'D' grade '150'\n";
			Bureaucrat D("D", 150);
			std::cout << D << std::endl;
			D.decrementGrade();
			std::cout << D << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Create Bureaucrat 'E' grade '151'\n";
		try
		{
			Bureaucrat E("E", 151);
			std::cout << E << std::endl;
			E.decrementGrade();
			std::cout << E << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}