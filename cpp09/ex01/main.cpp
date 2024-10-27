/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:23 by michang           #+#    #+#             */
/*   Updated: 2024/10/27 16:37:54 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "sstream"
#include "RPN.hpp"

int pintError(const std::string& error) {
	std::cerr << "Error: " << error << std::endl;
	return 1;
}


int main(int argc, char **argv) {
	std::string token;

	if (argc != 2)
		return pintError("Invalid number of arguments");

	RPN& rpn = RPN::getInstance();

	try {
		std::istringstream iss(argv[1]);
		while (iss >> token) {
			rpn.push(token);
			std::cout << "Token: " << token << std::endl;
		}
		std::cout << rpn.getResult() << std::endl;
	} catch (const std::string& e) {
		std::exit(pintError(e));
	}

	std::exit(0);
}