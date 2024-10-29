/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:12 by michang           #+#    #+#             */
/*   Updated: 2024/10/29 19:54:16 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN* RPN::_instance = 0;

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& obj) {
	(void)obj;
}

RPN& RPN::operator=(const RPN& obj) {
	(void)obj;
	return *this;
}

RPN& RPN::getInstance() {
	if (_instance == 0)
		_instance = new RPN();
	return *_instance;
}

void RPN::destroyInstance() {
	if (_instance != 0) {
		delete _instance;
		_instance = 0;
	}
}

void RPN::push(const std::string& token) {
	int a, b;

	if (token.length() != 1)
		throw std::string("Error");
	if (token[0] >= '0' && token[0] <= '9')
		_stack.push_back(token[0] - '0');
	else if ((token[0] == '+' || token[0] == '-' || token[0] == '*' ||
			  token[0] == '/') &&
			 _stack.size() > 1) {
		a = _stack.back();
		_stack.pop_back();
		b = _stack.back();
		_stack.pop_back();
		if (token[0] == '+')
			_stack.push_back(b + a);
		else if (token[0] == '-')
			_stack.push_back(b - a);
		else if (token[0] == '*')
			_stack.push_back(b * a);
		else if (token[0] == '/') {
			if (a == 0)
				throw std::string("Error");
			_stack.push_back(b / a);
		}
	} else
		throw std::string("Error");
}

int RPN::getResult() {
	if (_stack.size() != 1)
		throw std::string("Error");
	return _stack.back();
}