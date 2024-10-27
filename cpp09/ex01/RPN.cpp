/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:12 by michang           #+#    #+#             */
/*   Updated: 2024/10/27 16:40:07 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN* RPN::_instance = 0;

RPN::RPN() {}

RPN::~RPN() {}

RPN& RPN::getInstance() {
	if (_instance == 0)
		_instance = new RPN();
	return *_instance;
}

void RPN::push(const std::string& token) {
	int a, b, c;

	if (token.length() != 1)
		throw std::string("Invalid token");
	if (token[0] >= '0' || token[0] <= '9')
		_stack.push(std::atoi(token.c_str()));
	else if (token[0] == '+' || token[0] == '-' || token[0] == '*' ||
			 token[0] == '/') {
		if (_stack.size() < 2)
			throw std::string("Invalid number of operands");
		a = _stack.top();
		_stack.pop();
		b = _stack.top();
		_stack.pop();
		if (token[0] == '+')
			c = b + a;
		else if (token[0] == '-')
			c = b - a;
		else if (token[0] == '*')
			c = b * a;
		else if (token[0] == '/')
		{
			if (a == 0)
				throw std::string("Division by zero");
			c = b / a;
		}
		_stack.push(c);
	} else
		throw std::string("Invalid token");
}

int RPN::getResult() {
	if (_stack.size() != 1)
		throw std::string("Invalid number of operands");
	return _stack.top();
}